//import { Client, LocalStream, RemoteStream } from './ion-sdk.min.js';

// Get a local stream
const local = await IonSDK.LocalStream.getUserMedia({
    audio: true,
    video: true,
    simulcast: true, // enable simulcast
});