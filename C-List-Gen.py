#!/usr/bin/env python3
# coding : utf-8

import FDEditor as fde

if __name__ == "__main__":
    Normal = "./Data"
    FILENAME = "flash"
    l = fde.file2list(Normal)
    _type = "int"
    _name = "normal"
    x = []
    y = []
    w = []

    """ スプリット """
    for i, r in enumerate(l):
        v = r.split(",")
        x.append(float(v[0]))
        y.append(float(v[1]))
        w.append(float(v[2]))

    """ ヘッダファイルの作成 """
    f = open("./include/" + FILENAME + ".h", "w", encoding = "utf-8")
    f.write(f"#ifndef __{_name.upper()}_H__\r\n")
    f.write(f"#define __{_name.upper()}_H__\r\n")
    f.write(f"{_type} {_name}x[] = " + "{\r\n")
    for i, _x in enumerate(x):
        f.write(f"    {_x}" + (",\r\n" if i < len(x) - 1 else "\r\n    };\r\n\r\n"))
    f.write(f"{_type} {_name}y[] = " + "{\r\n")
    for i, _y in enumerate(y):
        f.write(f"    {_y}" + (",\r\n" if i < len(y) - 1 else "\r\n    };\r\n\r\n"))
    f.write(f"#endif\r\n")
    f.close()

    """ ソースファイルの作成 """
    f = open("./src/" + FILENAME + ".c", "w", encoding = "utf-8")
    f.close()

