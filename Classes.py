from pathlib import Path
import socket

class Malware:
    def __init__(self, content):
        self.content = content

    def display(self):
        Path(self.content).write_text('')

    def showip(self):
        hostname = socket.gethostname()
        ipadr = socket.gethostbyname(hostname)
        file_path = Path(self.content)
        with file_path.open('a') as file:
            file.write(f"\nYour ip address is {ipadr}")
        file.close()

virus1 = Malware('stored.txt')
virus1.display()
virus1.showip()



