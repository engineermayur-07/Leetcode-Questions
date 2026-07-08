<div align="center">

# 🧩 LeetCode Solutions

### *Consistency over intensity — one problem at a time.*

[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/)
[![Languages](https://img.shields.io/badge/Languages-C++%20%7C%20Python-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](#)
[![Workflow](https://img.shields.io/badge/Workflow-Branch%20per%20Question-orange?style=for-the-badge&logo=git&logoColor=white)](#-git-workflow)
[![Consistency](https://img.shields.io/badge/Daily-1--2%20Problems-brightgreen?style=for-the-badge&logo=googlecalendar&logoColor=white)](#)

[![Repo Size](https://img.shields.io/github/repo-size/engineermayur-07/LeetCode-Questions?style=flat-square&color=blueviolet)](#)
[![Last Commit](https://img.shields.io/github/last-commit/engineermayur-07/LeetCode-Questions?style=flat-square&color=informational)](#)
 

</div>

---

## 📖 About

This repo is a personal, growing archive of LeetCode problems I've solved — each with clean code and a proper write-up. It's built around three goals:

| Goal | What it looks like here |
|---|---|
| 🔁 **Consistency** | Solving 1–2 problems every single day, logged with dated commits |
| 🧠 **Practice** | Reinforcing core patterns — binary search, two pointers, sliding window, simulation, etc. |
| 🌿 **Git Literacy** | Practicing a real branch → merge workflow instead of committing straight to `main` |

> This isn't a "solve and forget" dump — every question gets its own explained approach and complexity breakdown, written the way I'd want to re-read it six months from now.

---

## 🗂️ Repo Structure

Each solved problem lives in its own folder, named after the question:

```
LeetCode-Solutions/
│
├── 1967-Number-of-Strings-That-Appear-as-Substrings-in-Word/
│   ├── ans.py
│   └── README.md
│
├── 28-Find-the-Index-of-First-Occurrence-in-a-String/
│   ├── ans.py
│   └── README.md
│
├── 278-First-Bad-Version/
│   ├── ans.py
│   └── README.md
│
├── ...
└── README.md   ← you are here
```

Every question folder follows the **same README template**, so browsing the repo always feels consistent:

1. 🏷️ **Problem Title & Difficulty** *(with link to the original problem)*
2. 📋 **Problem Statement** *(concise overview + constraints)*
3. 💡 **Approach / Intuition** *(step-by-step breakdown of the logic)*
4. ⏱️ **Complexity Analysis** *(Time — $O(...)$, Space — $O(...)$)*
5. 🔍 **Code Walkthrough** *(how the code maps to the approach)*

---

## 🌿 Git Workflow

This repo is also where I practice using Git the way it's meant to be used — branching per unit of work instead of pushing straight to `main`.

```
 main
   │
   ├──○ branch: First-Bad-Version      → solve → README → merge ──┐
   │                                                                   │
   ├──○ branch: Guess-Number-Higher-Or-Lower → solve → merge ──────┤
   │                                                                   │
   └────────────────────────────◄──────────────────────────────────────┘
```

**Steps for every question:**

1. 🌱 Create a new branch, named after the question.
2. 🧩 Solve it — write `ans.py` and its `README.md` on that branch.
3. 💾 Commit using a consistent, dated format:
   ```
   dd-mm-yyyy Question_Name
   ```
4. 🔀 Merge the branch back into `main`.

This keeps every problem's history isolated on its own branch before it joins `main` — good practice for branching, committing, and merging with real intent, not just habit.

---

## ✅ Why This Repo Exists

* 📅 **Daily habit** — solving 1–2 questions a day, rain or shine
* 🧩 **Pattern recognition** — building intuition across recurring problem types
* ✍️ **Written explanations** — every solution is documented with *why*, not just *what*
* 🌿 **Real Git practice** — branches, merges, and meaningful commit history

---

## 📈 Progress

More problems are added regularly as daily solving continues. Browse the folders above for the current, ever-growing set of solved questions — new ones land on `main` almost every day.

<div align="center">

*If you're browsing this — thanks for stopping by! Feel free to explore any solution folder.*

</div>

---
<h3 align="center">
  Prepared with 💙 by Mayur B Gund, a developer pursuing continuous learning.
</h3>