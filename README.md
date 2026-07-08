# LeetCode Solutions

A personal collection of LeetCode problems I've solved, organized one folder per question. This repo is as much about **daily practice and consistency** as it is about the solutions themselves — and it's also where I've been learning and practicing a proper **Git branching workflow**.

---

## Repo Structure

Each solved problem lives in its own folder, named after the question:

```
LeetCode-Solutions/
├── 1967-Number-of-Strings-That-Appear-as-Substrings-in-Word/
│   ├── ans.py
│   └── README.md
├── 28-Find-the-Index-of-First-Occurrence-in-a-String/
│   ├── ans.py
│   └── README.md
├── 278-First-Bad-Version/
│   ├── ans.py
│   └── README.md
├── ...
└── README.md   ← (this file)
```

Every question folder contains:
* **`ans.py`** — my solution code.
* **`README.md`** — a write-up of the problem following a consistent template:
  1. Problem Title & Difficulty (with link)
  2. Problem Statement
  3. Approach / Intuition
  4. Complexity Analysis (Time & Space)
  5. Code Walkthrough

---

## Git Workflow

This repo doubles as a sandbox for practicing Git properly instead of just committing straight to `main`. The workflow I follow for every question:

1. Create a new branch named after the question being solved.
2. Solve the problem and write the README on that branch.
3. Commit with the format:
   ```
   dd-mm-yyyy Question_Name
   ```
4. Merge the branch back into `main`.

This keeps every problem's history isolated on its own branch before joining the main line, which has been a good way to get comfortable with branching, committing, and merging in a low-stakes setting.

---

## Why This Repo Exists

* **Consistency** — Solving 1-2 questions a day and logging them, rain or shine.
* **Practice** — Reinforcing problem-solving patterns (two-pointer, binary search, sliding window, etc.) across a growing catalog.
* **Documentation** — Writing out the approach and complexity for each problem, both for my own future reference and to build the habit of explaining *why* a solution works, not just *what* it does.
* **Git Literacy** — Using branches and merges intentionally, rather than just pushing to `main`.

---

## Progress

More problems are added regularly as I continue solving daily. Check the folder list above (or browse the repo) for the current set of solved questions.
