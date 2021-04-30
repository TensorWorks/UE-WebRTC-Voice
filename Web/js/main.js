
/*
* The main entry point on the browser side to setup a WebRTC audio call with the SFU.
* @author Luke Bermingham
*/

const SessionName = "UE-BiDi-AUDIO-SESSION";

const PeerConnectionConfig = {
    iceServers: [
        {
            urls: "stun:stun.l.google.com:19302",
        },
    ]
};

// Generate unique identifiers: https://github.com/ai/nanoid#js
// Note: Could replace this with a more meaningful user id that is specific the application.
const nanoid=(t=21)=>{let e="",r=crypto.getRandomValues(new Uint8Array(t));for(;t--;){let n=63&r[t];e+=n<36?n.toString(36):n<62?(n-26).toString(36).toUpperCase():n<63?"_":"-"}return e};

class Main {

    constructor() 
    {
        // Setting up a WebRTC audio call with an SFU is composed of the following steps
        // 1. Create a local media stream in the browser using available user media (i.e mic).
        // 2. Create a "client" connection to the SFU using signalling.
        // 3. Publish the local media stream to the SFU using the client.
        this.userId = nanoid();
        console.log("Your user id is: " + this.userId);
        this.localStream = null;
        this.signal = new Signal.IonSFUJSONRPCSignal("ws://localhost:7000/ws");
        if(!this.signal)
        {
            throw new Error("Could not connect to signalling server for the SFU, aborting.");
        }
        this.client = new IonSDK.Client(this.signal, PeerConnectionConfig);
        this.client.ontrack = this.clientOnTrack.bind(this);
        this.signal.onopen = this.signallingServerOnOpen.bind(this); 
    }

    listenToAudioStream(stream)
    {
        var audio_elem = document.createElement("audio");
        audio_elem.srcObject = stream;
        audio_elem.play();
    }

    clientOnTrack(track, stream)
    {
        console.log("Client got 'ontrack' event fired.");
        console.log(track);
        console.log(stream);

        this.listenToAudioStream(stream);
    }

    signallingServerOnOpen()
    {
        // Connection to SFU through signalling server should come before we begin stream setup
        // this way we can't end up with a stream that is setup before the signalling server is
        // verified to be active and ready.
        this.client.join(SessionName, this.userId);
        this.setupLocalStream();
    }

    setupLocalStream() 
    {

        // Get a local audio stream
        const localStreamPromise = IonSDK.LocalStream.getUserMedia({
            audio: { autoGainControl: false, channelCount: 2, echoCancellation: false, latency: 0, noiseSuppression: false, sampleRate: 48000, sampleSize: 16, volume: 1.0 },
            video: false,
            simulcast: true, 
        });

        // Note: If we feel like we need higher quality audio we can try to munge the SDP to request higher average bitrate
        // as seen here: https://stackoverflow.com/a/58898163/1166082

        // When we successfully get the stream we will send it to the SFU.
        localStreamPromise.then(this.onLocalStreamSuccess.bind(this), this.onLocalStreamFailed.bind(this));
    }

    onLocalStreamSuccess(mediaStream) 
    {
        this.localStream = mediaStream;

        console.log("Client allowed us access to a media stream.")
        console.log(mediaStream);

        console.log("Publishing local media stream to the SFU.")
        this.client.publish(mediaStream);
    }

    onLocalStreamFailed(err)
    {
        console.error(err);
    }

}




// Main entrypoint (constructing Main will start a connection)
let main = new Main();