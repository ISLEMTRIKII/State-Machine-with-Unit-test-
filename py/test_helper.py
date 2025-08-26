import unittest
from py.helper_main import greet

class TestHelper(unittest.TestCase):
    def test_greet(self):
        self.assertEqual(greet("World"), "Hello, World! This is Python running inside Bazel.")

if __name__ == "__main__":
    unittest.main()
