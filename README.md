# 📒 Phonebook Manager (C Project)

A simple **console-based Phonebook Manager** written in C.  
It supports **loading contacts from a CSV file**, displaying them in a **colorful Unicode table**, **sorting**, **binary searching**, and **saving the sorted data back to a file**.

Built for learning & practicing:

✅ File I/O  
✅ Merge Sort & Quick Sort  
✅ Binary Search  
✅ Function pointers & comparators  
✅ ANSI color output  
✅ Menu-driven program design  

---

## 🖥️ Features

### 📂 Data
Each entry contains:

- **Name**
- **Phone Number**
- **City**

Data is loaded from:

phonebook.csv



(One entry per line — comma-separated)

---

### 📑 Menus

#### **Main Menu**
Sorting

Searching

Display Data

Exit




#### 🎯 **Sorting Menu**
- Choose algorithm:

Merge Sort

Quick Sort

Back



Then choose field:

Name

City

Phone Number

Back



Sorted data can be saved to a CSV file.

---

#### 🔍 Searching Menu
Uses **Binary Search** (auto-sorts before searching):

Search by Name

Search by Phone Number

Back



If found → result displays in a formatted table.

---

### 🎨 Colorful Unicode Table Output

Example display:
```text
┏━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃ No.  ┃ Name                         ┃ Phone Number         ┃ City                    ┃
┣━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃ 1    ┃ Karawan El Sharqi            ┃ 01012345678          ┃ Ottawa                  ┃
┃ 2    ┃ John Smith                   ┃ 01198765432          ┃ Giza                    ┃
┗━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┛
```



---

## 🏗️ Project Structure

```text
project/
│
├── include/
│ ├── definitions.h
│ ├── searching.h
│ ├── sorting.h
│ ├── fileio.h
│ └── helpers.h
│
├── src/
│ ├── main.c
│ ├── sorting.c
│ ├── searching.c
│ ├── fileio.c
│ └── helpers.c
│
├── phonebook.csv
└── README.md
```



---

## ⚙️ Build & Run

### GCC (Linux / macOS / MinGW)

```bash
gcc src/*.c -o phonebook
./phonebook
```

Using Make file
```bash
make run
```
Windows (UTF-8 Support Recommended)
To see Unicode borders correctly:

```bash
Copy code
chcp 65001
```
Or inside code:


Copy code
```bash
system("chcp 65001 > nul");
```
And make sure your editor saves files as UTF-8.

🧠 Algorithms Used
🔷 Sorting
Both:

Merge Sort

Quick Sort

They work via:

int (*cmp)(const Entry*, const Entry*)
Comparators:

compareByName

compareByCity

compareByNumber

🔎 Searching
Binary search works on sorted arrays and returns a pointer to the entry.

📥 Input File Format
phonebook.csv

```text
Name,Phone Number,City
John Smith,01012345678,Cairo
Sara Mohamed,01222222222,Alexandria
```
...


🚀 Future Improvements (Ideas)
Edit / delete entries

Add new entries interactively

Save automatically on exit

Case-insensitive search

Pagination when displaying large tables

Input validation

Unicode-safe width handling

### 🛡️ Requirements
C99+

A terminal that supports ANSI escape colors

UTF-8 font recommended

### ❤️ Author

Powerd by Yousef Essam for learning purposes.
Phonebook Manager created as a learning project for:

✔ Data structures
✔ Algorithms
✔ File handling in C

Feel free to modify & improve!