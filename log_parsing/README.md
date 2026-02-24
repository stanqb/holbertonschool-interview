## Input Format

```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

Lines that do not match this format are skipped.

## Output

- **Total file size**: cumulative sum of all file sizes read so far
- **Number of lines per status code** (in ascending order): `200`, `301`, `400`, `401`, `403`, `404`, `405`, `500`

## Requirements

- Python 3.4.3 on Ubuntu 14.04 LTS
- PEP 8 style (version 1.7.x)
- All files must be executable

## Usage

```bash
./0-generator.py | ./0-stats.py
```

## Files

| File | Description |
|---|---|
| `0-stats.py` | Main log parsing script |

## Repository

- **GitHub**: `holbertonschool-interview`
- **Directory**: `log_parsing`