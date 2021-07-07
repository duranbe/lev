# lev
Levenshtein distance function as C Extension for Python 3


See https://en.wikipedia.org/wiki/Levenshtein_distance 

## Install

```bash
python3 setup.py install
```

## Use

```python
>>> import levenshtein
>>> levenshtein.levenshtein("TEST","TESTS")
1
>>> levenshtein.levenshtein("DOG","DOGGOS")
3
```
