from distutils.core import setup, Extension

def main():
	setup(name="levenshtein",
		version="0.0.1",
		description="Levenshtein Distance implemented as C Extension for Python 3",
		ext_modules=[Extension("levenshtein",["src/levenshtein.c"])]
		)

if __name__ == "__main__":
	main()