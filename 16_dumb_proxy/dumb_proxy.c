/*

Project 16: The "dumb" Proxy
Goal: Managing two sockets at once.

Why: This is Project 2. A proxy sits between a Client and a Server.

The Task:

Open a Server Socket (listen on 8080).

When a Client connects, open a new Client Socket to google.com:80.

Read from the Client -> Write to Google.

Read from Google -> Write to the Client.

(Do this with a simple buffer loop).

*/