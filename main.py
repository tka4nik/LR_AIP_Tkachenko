import random
import string


class FileGenerator:

    def __init__(self):
        self.fileqnt = 0

    def generate_text(self, length, n):
        filename = "text/char_" + str(n) + "_" + str(length) + ".txt"
        with open(filename, "w") as s:
            for i in range(1, n * 100000):
                tmp = ''.join(
                    random.choices(string.ascii_uppercase + string.digits + string.ascii_lowercase + string.punctuation,
                                   k=length * random.randint(19, 39) + 1)) + "\n"
                s.write(tmp)
            self.fileqnt += 1

    def generate_int(self, n):
        filename = "int/int_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for i in range(1, n * 100000):
                tmp = ''.join(str(random.randint(-100000, 100000))) + "\n"
                s.write(tmp)
            self.fileqnt += 1

    def generate_float(self, n):
        filename = "float/float_" + str(n) + ".txt"
        with open(filename, "w") as s:
            for i in range(1, n * 100000):
                tmp = str(random.uniform(-100000, 100000)) + "\n"
                s.write(tmp)
            self.fileqnt += 1


if __name__ == "__main__":
    FG = FileGenerator()
    for i in range(1, 11):
        FG.generate_text(0, i)
        FG.generate_text(1, i)
        FG.generate_int(i)
        FG.generate_float(i)
    print("File quantity: " + str(FG.fileqnt))
