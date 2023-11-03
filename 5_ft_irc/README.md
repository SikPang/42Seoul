> 본 프로그램은 Mac OS 에서만 구동되며, irssi 클라이언트에 맞춰 개발되었습니다

![ezgif com-video-to-gif (2)](https://github.com/SikPang/42Seoul/assets/87380790/d6fb46e3-d937-416d-b81a-8e5d68822ace)

# Introduction

- <a href="https://en.wikipedia.org/wiki/Internet_Relay_Chat" target="_blank">Internet Relay Chat</a> or IRC is a text-based communication protocol on the Internet.
- It offers real-time messaging that can be either public or private. Users can exchange direct messages and join group channels.
- IRC clients connect to IRC servers in order to join channels. IRC servers are connected together to form a network.

<br/>

# Implementation

- The server must be capable of handling multiple clients at the same time and never hang.
- Forking is not allowed. All I/O operations must be non-blocking.
- Only 1 poll() (or equivalent) can be used for handling all these operations (read,
write, but also listen, and so forth).
- Several IRC clients exist. You have to choose one of them as a reference. Your
reference client will be used during the evaluation process.
- Your reference client must be able to connect to your server without encountering any error.
- Communication between client and server has to be done via TCP/IP (v4 or v6).
- Using your reference client with your server must be similar to using it with any
official IRC server. However, you only have to implement the following features:
  - You must be able to authenticate, set a nickname, a username, join a channel,
send and receive private messages using your reference client.
  - All the messages sent from one client to a channel have to be forwarded to
every other client that joined the channel.
  - You must have operators and regular users.
  - Then, you have to implement the commands that are specific to channel operators:
    - KICK - Eject a client from the channel
    - INVITE - Invite a client to a channel
    - TOPIC - Change or view the channel topic
    - MODE - Change the channel’s mode:
      - i: Set/remove Invite-only channel
      - t: Set/remove the restrictions of the TOPIC command to channel operators
      - k: Set/remove the channel key (password)
      - o: Give/take channel operator privilege
      - l: Set/remove the user limit to channel

<br/>

# Usage
```
./ircserv [server port] [server password]
```

### Running the server
```
make && ./ircserv 4242 1234
```

### Connect as client with nc
```
nc 127.0.0.1 4242
USER me me 127.0.0.1 [your hostName]
PASS 1234
NICK user1
```
```
JOIN #newCh
```
```
PRIVMSG #newCh :my text
```

<br/>

# Screen shots

![ezgif com-video-to-gif](https://github.com/SikPang/42Seoul/assets/87380790/9513cec1-c6bc-4fb2-89d0-af13ed5b14ac)
![ezgif com-video-to-gif (1)](https://github.com/SikPang/42Seoul/assets/87380790/8b3f7d43-01f9-4f20-aaef-0b1520f7b8ea)

