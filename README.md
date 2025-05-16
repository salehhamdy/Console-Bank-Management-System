# Console Bank Management System (C++)

A lightweight, menu‑driven **Bank Management System** implemented in modern C++ (C++17).  It runs entirely in memory and showcases basic data‑structure design (linked lists, queues, stacks, and a simple quick‑sort) while allowing users to register, log in, manage up to five recent transactions, and inspect personal details – all from the terminal.

---

## Folder / File Overview

| Path / File | Purpose |
|-------------|---------|
| `.vscode/` | Launch / build config for Visual Studio Code (optional). |
| `details.txt` | *Sample* text info (currently unused by the program – handy for notes). |
| `inventory_system.exe` | Old compiled executable from a different project – **not used** here but left in the screenshot. |
| `main.cpp` | **Entry‑point** that drives the CLI menus and orchestrates all operations. |
| `LinkedList.h` | Generic singly‑linked‑list node template used for the client lists. |
| `Queue.h` / `Queue.cpp` | Queue ADT (not invoked in `main.cpp` but available for expansion). |
| `Stack.h` / `Stack.cpp` | Stack ADT (idem). |
| `Tree.h` | Binary‑tree skeleton (planned extension). |
| `SparePart.h` / `SparePart.cpp`, `Supplier.h` / `Supplier.cpp` | Artifacts from an inventory example (safe to delete if unused). |

> **Note**  Only `main.cpp` and `LinkedList.h` are strictly required for the current banking demo; the other modules are included to illustrate additional DS/ADT implementations.

---

## Key Features

* **Client account creation** with random ID assignment.
* **Secure login** (rudimentary – email & password stored in memory only).
* **Password recovery** via email lookup.
* **Transactions menu**  – create ≤5 transactions, list recent, delete by ID.
* **Linked‑list sharding**  – clients are stored across **10 separate linked lists** (simulating hash‑bucket distribution).  Size stats for each list can be printed.
* **Quick Sort of buckets** by list size — demonstrates a simple in‑place quick‑sort template operating on the array of linked lists.

---

## Build & Run

### Prerequisites

* **C++17‑compatible compiler** (g++ ≥ 9, clang ≥ 10, MSVC 2019+, etc.)
* A terminal / command prompt

### Compilation

```bash
# Linux / macOS / WSL
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Queue.cpp Stack.cpp SparePart.cpp Supplier.cpp -o bank_system

# Windows (MinGW)
mingw32-g++ -std=c++17 -static -O2 main.cpp Queue.cpp Stack.cpp SparePart.cpp Supplier.cpp -o bank_system.exe
```

The auxiliary CPP files are optional—omit them if you removed the corresponding headers.

### Running

```bash
./bank_system       # or bank_system.exe on Windows
```

Follow the on‑screen menu prompts:

```
=============================================================
###############Welcome to the bank system################
1. Login to your account
2. New Client
3. Forgot your password
4. Quick sort
5. Exit
Enter your choice: _
```

---

## Usage Walkthrough

1. **New Client** – supply *name, email, phone, password, address* to register. You’ll be bucketed into one of 10 linked lists and given a random ID.
2. **Login** – sign in with the same email/password.
3. Once logged in you reach **Home**:
    * **Transactions** → manage up to five transactions (create, delete, list).
    * **Show personal info** → prints your stored record.
    * **Sign out** → return to main menu.
4. **Quick sort** on the main menu prints the size of every bucket, sorts the buckets by size, and prints again so you can observe the algorithm’s effect.

> ⚠️ **Persistence** – All data live in memory; exiting the program clears everything.  If you need long‑term storage, consider serializing to a file or integrating SQLite/MySQL.

---

## Extending the Project

| Idea | Hint |
|------|------|
| **Persist data** | Serialize clients/transactions to JSON or a lightweight DB. |
| **Hash table buckets** | Replace fixed 10‑list array with a true hash map keyed by email. |
| **Unit tests** | Add Catch2 or GoogleTest for the ADT modules. |
| **Encryption** | Store password hashes (e.g., bcrypt) instead of plaintext. |
| **GUI** | Port the menus to Qt or ImGui for a desktop UI. |
| **REST API** | Wrap the logic in a micro‑service using Pistache or Crow. |

---

## Known Limitations / Todos

* No input‑sanitization for whitespace; `cin >>` breaks on spaces.
* Re‑entering invalid menu numbers sometimes prints the error **after** the header instead of before – harmless but cosmetic.
* Auxiliary DS files (Queue/Stack/Tree) aren’t used by `main.cpp`; prune or integrate.

---

## License

This sample project is released under the MIT License.  See the **LICENSE** file (create one if needed).

---

## Author

Replace this section with your name, contact, and any acknowledgments.
