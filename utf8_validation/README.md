# UTF-8 Validation

## Description

Determines if a given data set represents a valid UTF-8 encoding. Each integer in the list represents 1 byte (only the 8 least significant bits are used).

## Requirements

- Ubuntu 14.04 LTS
- Python 3.4.3
- PEP 8 style (version 1.7.x)

## Files

| File | Description |
|------|-------------|
| `0-validate_utf8.py` | Validates a UTF-8 encoded data set |

## Algorithm

UTF-8 encoding rules:
- 1 byte:  `0xxxxxxx`
- 2 bytes: `110xxxxx 10xxxxxx`
- 3 bytes: `1110xxxx 10xxxxxx 10xxxxxx`
- 4 bytes: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`

For each byte: if we expect a continuation byte (`10xxxxxx`), verify it. Otherwise determine how many continuation bytes follow from the leading bits.

## Usage

```python
validUTF8 = __import__('0-validate_utf8').validUTF8
print(validUTF8([65]))        # True
print(validUTF8([229, 65]))   # False
```
