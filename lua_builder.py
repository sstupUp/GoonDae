import sys
from collections import deque

filename = ""
result = []


def build_struct(filename):
    cnt = 0
    add_cnt = 0

    result.append("\"\", 1,\n")
    result_name = filename[:-4] + "_lus_struct" + ".txt"
    print("Building ", result_name, " from", filename, "...\n")

    with open(filename, "r+") as f:
        l = f.readlines()

        for i in l:
            cnt = 0
            tmp_len = 0
            add_cnt = 0

            if i == '\n':
                print("\r")
                dummy = "\"\", 1,\n"
            else:
                if i[-1] == '\n':
                    i = i[:-1]

                tmp = list(i)

                while True:
                    try:
                        c = tmp[cnt]
                    except:
                        break
                    if c == "\\" or c == "\"" or c == "\r" or c == "\n":
                        tmp.insert(cnt, "\\")
                        cnt += 2
                        add_cnt += 1
                    else:
                        cnt += 1



                i = "".join([str(item) for item in tmp])
                print(i)
                dummy = "\"" + i + "\", 1,\n"

            result.append(dummy)

    result.append("NULL, 0,\r")
    res = deque(result)

    with open(result_name, "w+") as f2:
        while True:
            try:
                tmp = res.popleft()
            except:
                break

            f2.write(tmp)
    print("\n...Done!")

if __name__ == "__main__":
    len_arg = len(sys.argv)

    if len_arg != 2:
        print("Usage: python lua_builder.py [LUA_COMMAND_FILE.lua or .txt]")
        exit(1)

    filename = sys.argv[1]
    build_struct(filename)