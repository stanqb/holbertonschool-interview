# Lockboxes

## Description
This project implements a method to determine if all locked boxes can be opened. Given n number of locked boxes numbered from 0 to n-1, each box may contain keys to other boxes. The challenge is to determine if all boxes can be unlocked starting from box 0, which is initially unlocked.

## Requirements
- **Allowed editors:** `vi`, `vim`, `emacs`
- **Environment:** Ubuntu 14.04 LTS with Python 3 (version 3.4.3)
- **Coding style:** PEP 8 (version 1.7.x)
- **File requirements:**
  - All files must end with a new line
  - First line must be exactly `#!/usr/bin/python3`
  - All files must be executable
  - Code must be documented

## Algorithm
The solution implements a graph traversal approach where:
- Each box represents a node
- Keys represent edges to other boxes
- Starting from box 0, we explore all reachable boxes
- Return `True` if all boxes can be reached, `False` otherwise

## Function Prototype
```python
def canUnlockAll(boxes)
```

### Parameters
- `boxes`: A list of lists where each sublist contains keys (positive integers)
- The first box `boxes[0]` is unlocked by default
- Keys may reference non-existent boxes (ignored)

### Returns
- `True` if all boxes can be opened
- `False` if some boxes remain locked

## Usage Example
```python
#!/usr/bin/python3
canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Files
- `0-lockboxes.py`: Main implementation file
- `main_0.py`: Test file (for testing purposes)

## Repository Structure
```
holbertonschool-interview/
└── lockboxes/
    ├── README.md
    ├── 0-lockboxes.py
    └── main_0.py
```
