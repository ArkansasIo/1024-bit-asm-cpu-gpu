#!/usr/bin/env python3
import unittest
from arkan_gpu import MASK, dispatch

class ArkanGpuTests(unittest.TestCase):
    def test_add_and_mask_to_10000_bits(self):
        self.assertEqual(dispatch("add", [MASK], [1]), [0])
    def test_bitwise_operations(self):
        self.assertEqual(dispatch("xor", [0b1010], [0b1100]), [0b0110])
        self.assertEqual(dispatch("and", [0b1010], [0b1100]), [0b1000])
        self.assertEqual(dispatch("or", [0b1010], [0b1100]), [0b1110])
    def test_length_mismatch_rejected(self):
        with self.assertRaises(ValueError):
            dispatch("add", [1], [])
    def test_out_of_range_rejected(self):
        with self.assertRaises(ValueError):
            dispatch("xor", [MASK + 1], [0])

if __name__ == "__main__":
    unittest.main()
