# Minimum Operations

## Description

Given a text file with a single character `H`, and only two operations available — **Copy All** and **Paste** — find the minimum number of operations to get exactly `n` H characters.

## Requirements

- Ubuntu 14.04 LTS
- Python 3.4.3
- PEP 8 style (version 1.7.x)

## Files

| File | Description |
|------|-------------|
| `0-minoperations.py` | Returns the minimum number of operations to reach n H's |

## Algorithm

The key insight is **prime factorization**: to reach `n` characters optimally, you always copy at a prime factor boundary. The answer is the sum of all prime factors of `n`.

**Example:** `n = 12 = 2 × 2 × 3` → `2 + 2 + 3 = 7 operations`

## Usage

```python
minOperations = __import__('0-minoperations').minOperations
print(minOperations(9))   # 6
print(minOperations(12))  # 7
```
