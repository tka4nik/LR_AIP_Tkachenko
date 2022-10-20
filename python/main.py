import random
import string


class FileGenerator:

    def __init__(self):
        self.fileqnt = 0

    def generate_char(self, n):
        filename = "char/char_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for _ in range(1, n * 100000 + 1):
                tmp = ''.join(random.choices(string.ascii_uppercase + string.digits + string.ascii_lowercase + string.punctuation, k=1)) + "\n"
                s.write(tmp)
            self.fileqnt += 1

    def generate_int(self, n):
        filename = "int/int_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for _ in range(1, n * 100000 + 1):
                tmp = ''.join(str(random.randint(-100000, 100000))) + "\n"
                s.write(tmp)
            self.fileqnt += 1

    def generate_double(self, n):
        filename = "double/double_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for _ in range(1, n * 100000 + 1):
                tmp = str(random.uniform(-100000, 100000)) + "\n"
                s.write(tmp)
            self.fileqnt += 1

    def generate_string(self, n):
        filename = "string/string_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for _ in range(1, n * 100000 + 1):
                tmp = ''.join(random.choices(string.ascii_uppercase + string.digits + string.ascii_lowercase + ' ', k=random.randint(20, 40))) + "\n"
                s.write(tmp)
            self.fileqnt += 1


if __name__ == "__main__":
    FG = FileGenerator()
    for i in range(1, 11):
        FG.generate_char(i)
        FG.generate_string(i)
        FG.generate_int(i)
        FG.generate_double(i)
    print("File quantity: " + str(FG.fileqnt))
