import sys
import collections

def print_map(m):
    for key, value in m.items():
        print(f"{{{key}: {value}}}")

def sort_map(m):
    sorted_map = dict(sorted(m.items(), key=lambda item: item[1]))
    return sorted_map

def single_letter(filename):
    m = collections.defaultdict(int)
    with open(filename, 'r') as fp:
        s = ''.join(fp.readlines())
        for c in s:
            if c.isalpha():
                m[c.lower()] += 1
    m = sort_map(m)
    print_map(m)
    print("\n- End of Single Letter Frequencies -\n")

def bigram(filename):
    m = collections.defaultdict(int)
    with open(filename, 'r') as fp:
        words = fp.read().split()
        for word in words:
            for i in range(len(word) - 1):
                if word[i:i+2].isalpha() and len(word[i:i+2]) == 2:
                    m[word[i:i+2].lower()] += 1
    m = sort_map(m)
    print_map(m)
    print("\n- End of Bigram Frequencies -\n")

def trigram(filename):
    m = collections.defaultdict(int)
    with open(filename, 'r') as fp:
        words = fp.read().split()
        for word in words:
            for i in range(len(word) - 2):
                if word[i:i+3].isalpha() and len(word[i:i+3]) == 3:
                    m[word[i:i+3].lower()] += 1
    m = sort_map(m)
    print_map(m)
    print("\n- End of Trigram Frequencies -\n")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <filename>")
    else:
        filename = sys.argv[1]
        single_letter(filename)
        bigram(filename)
        trigram(filename)