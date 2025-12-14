import socket

def scan_port(ip, port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)
        result = sock.connect_ex(ip, port)
        sock.close()
        return result == 0
    except:
        return False

hostname = socket.gethostname()

ipaddr = socket.gethostbyname(hostname)
common_ports = [80,443, 22, 21]

for port in common_ports:
    if scan_port(ipaddr, port):
        print(f"{port} is open")
    else:
        print(f"{port} is closed")




