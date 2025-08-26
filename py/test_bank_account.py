# py/test_bank_account.py
import unittest
from py.bank_account_main import BankAccount

class TestBankAccount(unittest.TestCase):
    def test_deposit(self):
        account = BankAccount()
        self.assertEqual(account.deposit(100), 100)
        self.assertEqual(account.get_balance(), 100)

    def test_withdraw(self):
        account = BankAccount(200)
        self.assertEqual(account.withdraw(50), 150)
        self.assertEqual(account.get_balance(), 150)

    def test_overdraw(self):
        account = BankAccount(50)
        self.assertEqual(account.withdraw(100), 50)  # balance unchanged
        self.assertEqual(account.get_balance(), 50)

if __name__ == "__main__":
    unittest.main()
