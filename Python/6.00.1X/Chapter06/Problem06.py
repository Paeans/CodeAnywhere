import string
def buildCoder(shift):
    """
    Returns a dict that can apply a Caesar cipher to a letter.
    The cipher is defined by the shift value. Ignores non-letter characters
    like punctuation, numbers, and spaces.

    shift: 0 <= int < 26
    returns: dict
    """
    ### TODO 
    result = {}
    charlist = [str(string.ascii_lowercase), str(string.ascii_uppercase)]
    for clist in charlist:
        size = len(clist)
        for i in range(size):
                result[clist[i]] = clist[(i + shift) % size]
    return result

def applyCoder(text, coder):
    """
    Applies the coder to the text. Returns the encoded text.

    text: string
    coder: dict with mappings of characters to shifted characters
    returns: text after mapping coder chars to original text
    """
    ### TODO
    result = ''
    for e in text:
        if e in coder.keys(): result += coder[e]
        else: result += e
    return result

def applyShift(text, shift):
    """
    Given a text, returns a new text Caesar shifted by the given shift
    offset. Lower case letters should remain lower case, upper case
    letters should remain upper case, and all other punctuation should
    stay as it is.

    text: string to apply the shift to
    shift: amount to shift the text (0 <= int < 26)
    returns: text after being shifted by specified amount.
    """
    ### TODO.
    ### HINT: This is a wrapper function.
    return applyCoder(text, buildCoder(shift))

def countNum(wordList, plaintext):
    result = 0
    words = plaintext.split(' ')
    for word in words:
        if isWord(wordList, word): result += 1  ### Unimplement
    return result

def findBestShift(wordList, text):
    """
    Finds a shift key that can decrypt the encoded text.

    text: string
    returns: 0 <= int < 26
    """
    ### TODO
    shift = 0
    wordNum = 0
    for i in range(26):
        plaintext = applyShift(text, i)
        tmp = countNum(wordList, plaintext)
        if tmp > wordNum: 
            wordNum = tmp
            shift = i
    return shift

def decryptStory():
    """
    Using the methods you created in this problem set,
    decrypt the story given by the function getStoryString().
    Once you decrypt the message, be sure to include as a comment
    your decryption of the story.

    returns: string - story in plain text
    """
    ### TODO
    story = getStoryString()
    shift = findBestShift(loadWords(), story)
    return applyShift(story, shift)