import socket
import threading

# IP = socket.gethostbyname(socket.gethostname())
# PORT = 5566
# ADDR = (IP, PORT)
# SIZE = 1024
# FORMAT = "utf-8"
# DISCONNECT_MSG = "!DISCONNECT"

# def main():
#     client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     client.connect(ADDR)
#     print(f"[CONNECTED] Client connected to server at {IP}:{PORT}")

#     connected = True
#     while connected:
#         msg = input("> ")

#         client.send(msg.encode(FORMAT))

#         if msg == DISCONNECT_MSG:
#             connected = False
#         else:
#             msg = client.recv(SIZE).decode(FORMAT)
#             print(f"[SERVER] {msg}")

# if __name__ == "__main__":
#     main()

nickname = input('Choose a nickname: ')

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 80))

def receive():
    while True:
        try:
            message = client.recv(1024).decode('ascii')
            if message == 'NICK':
                client.send(nickname.encode('ascii'))
            else:
               print(message)
        except:
            print('An error occurred!')
            client.close()
            break

def write():
    while True:
        message = f'{nickname}: {input("")}'
        client.send(message.encode('ascii'))

receive_thread = threading.Thread(target=receive)
receive_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()