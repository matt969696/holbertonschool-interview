#!/usr/bin/python3
"""
This module contains functions for lockbox problem
"""


def unlockBox(box, boxes, opened, nbbox):
    """unlock a specific box and updates opened"""
    """print("Unlocking box", box, "with open", opened)"""
    newopen = dict(opened)
    for b in boxes[box]:
        if b not in newopen.keys() and b < nbbox and isinstance(b, int):
            newopen[b] = None
            newopen.update(unlockBox(b, boxes, newopen, nbbox))
    return newopen


def canUnlockAll2(boxes):
    """determines if all the boxes can be opened"""
    """print("--------------")"""
    listoflist = all(isinstance(elem, list) for elem in boxes)
    if listoflist is False:
        """print("Not a list of list")"""
        return False

    nbbox = len(boxes)
    testdic = {0: None}
    for elem in boxes:
        for b in elem:
            if b not in testdic.keys() and b < nbbox and isinstance(b, int):
                testdic[b] = None
    if len(testdic) != nbbox:
        """print("Not enough keys found")"""
        return(False)

    opstart = {0: None}
    opend = unlockBox(0, boxes, opstart, nbbox)
    if len(opend) == nbbox:
        """print("Yesss")"""
        return True
    """print("Noooo")"""
    return(False)



def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""
    """print("--------------")"""
    listoflist = all(isinstance(elem, list) for elem in boxes)
    if listoflist is False:
        """print("Not a list of list")"""
        return False

    nbbox = len(boxes)
    """
    testdic = {0: None}
    for elem in boxes:
        for b in elem:
            if b not in testdic.keys() and b < nbbox and isinstance(b, int):
                testdic[b] = None
    if len(testdic) != nbbox:
        print("Not enough keys found")
        return(False)
    """

    opend = [0 for i in range(nbbox)]
    opend[0] = 1
    toopen = [0]
    while toopen:
        n = toopen.pop()
        for i in boxes[n]:
            if not opend[i] and i < nbbox and isinstance(i, int):
                opend[i] = 1
                toopen.append(i)
    if sum(opend) == nbbox:
        """print("Yesss")"""
        return True
    """print("Noooo")"""
    return(False)
