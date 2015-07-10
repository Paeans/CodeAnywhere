import string
def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    result = ''
    for i in range(0, 26):
        char = string.ascii_lowercase[i]
        if char not in lettersGuessed:
            result += char
    return result

def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    result = ''
    for i in range(0, len(secretWord)):
        if secretWord[i] not in lettersGuessed: result += '_ '
        else: result += secretWord[i]
    return result

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    for i in range(0, len(secretWord)):
        if secretWord[i] not in lettersGuessed: return False
    return True


def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...
    print 'Welcome to the game Hangman!'
    print 'I am thinking of a word that is ', len(secretWord), ' letters long'
    print '-----------'
    guessLeft = 8
    lettersGuessed = []
    while guessLeft > 0:
        print 'You have', guessLeft, 'guesses left.'
        print 'Available letters:', getAvailableLetters(lettersGuessed)
        print 'Please guess a letter:',
        guessChar = ''
        guessChar = raw_input()
        guessChar = guessChar.lower()
        promot = ''
        if guessChar in lettersGuessed: promot = 'Oops! You\'ve already guessed that letter:'
        elif guessChar in secretWord: 
            promot = 'Good guess:'
            print len(guessChar), [guessChar]
            lettersGuessed.append(guessChar)
        else: promot = 'Oops! That letter is not in my word:'
        print lettersGuessed
        print promot, getGuessedWord(secretWord, lettersGuessed)
        print '-----------'
        if isWordGuessed(secretWord, lettersGuessed): break
        guessLeft -= 1
    if guessLeft == 0:
        print 'Sorry, you ran out of guesses. The word was else.'
    else:
        print 'Congratulations, you won!'
hangman('abc')