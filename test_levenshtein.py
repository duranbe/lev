import unittest
from levenshtein import levenshtein


class TestLevenshteinMethod(unittest.TestCase):

    def test_test(self):
        self.assertEqual(levenshtein('TEST','TESTS'), 1)

    def test_doggos(self):
        self.assertEqual(levenshtein('dog','doggos'), 3)

    def test_bonjour(self):
    	self.assertEqual(levenshtein('bonjour','bonsoir'), 2)

if __name__ == '__main__':
    unittest.main()