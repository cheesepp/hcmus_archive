import socket
import threading


# IP = socket.gethostbyname(socket.gethostname())
# PORT = 5566
# ADDR = (IP, PORT)
# SIZE = 1024
# FORMAT = "utf-8"
# DISCONNECT_MSG = "!DISCONNECT"

# def handle_client(conn, addr):
#     print(f"[NEW CONNECTION] {addr} connected.")

#     connected = True
#     while connected:
#         msg = conn.recv(SIZE).decode(FORMAT)
#         if msg == DISCONNECT_MSG:
#             connected = False

#         print(f"[{addr}] {msg}")
#         msg = f"Msg received: {msg}"
#         conn.send(msg.encode(FORMAT))

#     conn.close()

# def main():
#     print("[STARTING] Server is starting...")
#     server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     server.bind(ADDR)
#     server.listen()
#     print(f"[LISTENING] Server is listening on {IP}:{PORT}")

#     while True:
#         conn, addr = server.accept()
#         thread = threading.Thread(target=handle_client, args=(conn, addr))
#         thread.start()
#         print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")

# if __name__ == "__main__":
#     main()

host = "127.0.0.1"
port = 80

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()

clients = []
nicknames = []

def broadcast(message):
    for client in clients:
        client.send(message)

def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except: 
            index = clients.index(client)
            clients.remove(client)
            clients.close()
            nickname = nicknames[index]
            broadcast(f'{nickname} left the chat!'.encode('ascii'))
            nicknames.remove(nickname)
            break

def receive():
    while True:
        client, address = server.accept()
        print(f'Connected with {str(address)}')
        client.send('NICK'.encode('ascii'))
        nickname = client.recv(1024).decode('ascii')
        nicknames.append(nickname)
        clients.append(client)

        print(f'Nickname of the client is {nickname}!')
        broadcast(f'{nickname} joined the chat!'.encode('ascii'))
        client.send('Connected to the server!'.encode('ascii'))

        thread = threading.Thread(target=handle, args = (client,))
        thread.start()

print('Server is listening....')
receive()
