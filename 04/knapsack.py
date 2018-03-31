#!/usr/bin/python3
# from https://rosettacode.org/wiki/Knapsack_problem/Continuous#Python
# NAME, WEIGHT, VALUE (for this weight)
items = [("0", 30, 60),
         ("1", 100, 50),
         ("2", 10, 40),
         ("3", 10, 30),
         ("4", 8, 20),
         ("5", 8, 10),
         ("6", 1, 5),
         ("7", 1, 1)]

MAXWT = 30.0

sorted_items = sorted(((value/amount, amount, name)
                       for name, amount, value in items),
                      reverse = True)
wt = val = 0
bagged = []
for unit_value, amount, name in sorted_items:
    portion = min(MAXWT - wt, amount)
    wt     += portion
    addval  = portion * unit_value
    val    += addval
    bagged += [(name, portion, addval)]
    if wt >= MAXWT:
        break

print("    ITEM   PORTION VALUE")
print("\n".join("%10s %6.2f %6.2f" % item for item in bagged))
print("\nTOTAL WEIGHT: %5.2f\nTOTAL VALUE: %5.2f" % (wt, val))
