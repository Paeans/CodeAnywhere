import string

class NewsStory(object):
    def __init__(self, guid, title, subject, summary, link):
        self.id, self.tl, self.sub, self.smry, self.link = \
            guid, title, subject, summary, link
        
    def getGuid(self):
        return self.id
    
    def getTitle(self):
        return self.tl
    
    def getSubject(self):
        return self.sub
    
    def getSummary(self):
        return self.smry
    
    def getLink(self):
        return self.link

class Trigger(object):
    def evaluate(self, story):
        """
        Returns True if an alert should be generated
        for the given news item, or False otherwise.
        """
        raise NotImplementedError
        
class WordTrigger(Trigger):
    def __init__(self, word):
        self.word = word
        
    def isWordIn(self, text):
        tmp = text
        for e in string.punctuation:
            tmp = tmp.replace(e, ' ')
        return self.word.lower() in tmp.lower().split(' ')
    
class TitleTrigger(WordTrigger):
    def evaluate(self, story):
        return self.isWordIn(story.getTitle())
    
class SubjectTrigger(WordTrigger):
    def evaluate(self, story):
        return self.isWordIn(story.getSubject())
    
class SummaryTrigger(WordTrigger):
    def evaluate(self, story):
        return self.isWordIn(story.getSummary())

class NotTrigger(Trigger):
    def __init__(self, wordTrigger):
        self.wordTrigger = wordTrigger
        
    def evaluate(self, story):
        return not self.wordTrigger.evaluate(story)
    
class AndTrigger(Trigger):
    def __init__(self, wordTrigger1, wordTrigger2):
        self.wt1 = wordTrigger1
        self.wt2 = wordTrigger2
        
    def evaluate(self, story):
        return self.wt1.evaluate(story) and self.wt2.evaluate(story)

class OrTrigger(Trigger):
    def __init__(self, wordTrigger1, wordTrigger2):
        self.wt1 = wordTrigger1
        self.wt2 = wordTrigger2
        
    def evaluate(self, story):
        return self.wt1.evaluate(story) or self.wt2.evaluate(story)
    
class PhraseTrigger(Trigger):
    def __init__(self, phrase):
        self.phrase = phrase
        
    def evaluate(self, story):
        return self.phrase in story.getTitle() \
                or self.phrase in story.getSubject() \
                or self.phrase in story.getSummary()
            
def filterStories(stories, triggerlist):
    result = []
    for story in stories:
        for trigger in triggerlist:
            if trigger.evaluate(story):
                result.append(story)
                break    
    return result

def makeTrigger(triggerMap, triggerType, params, name):
    """
    Takes in a map of names to trigger instance, the type of trigger to make,
    and the list of parameters to the constructor, and adds a new trigger
    to the trigger map dictionary.

    triggerMap: dictionary with names as keys (strings) and triggers as values
    triggerType: string indicating the type of trigger to make (ex: "TITLE")
    params: list of strings with the inputs to the trigger constructor (ex: ["world"])
    name: a string representing the name of the new trigger (ex: "t1")

    Modifies triggerMap, adding a new key-value pair for this trigger.

    Returns a new instance of a trigger (ex: TitleTrigger, AndTrigger).
    """
    trigger = None
    if   triggerType == 'TITLE':   trigger = TitleTrigger(params[0])
    elif triggerType == 'SUBJECT': trigger = SubjectTrigger(params[0])
    elif triggerType == 'SUMMARY': trigger = SummaryTrigger(params[0])
    elif triggerType == 'NOT':     trigger = NotTrigger(triggerMap[params[0]])
    elif triggerType == 'AND':     trigger = AndTrigger(triggerMap[params[0]], triggerMap[params[1]])
    elif triggerType == 'OR':      trigger = OrTrigger(triggerMap[params[0]], triggerMap[params[1]])
    elif triggerType == 'PHRASE':  trigger = PhraseTrigger(' '.join(params))
    triggerMap[name] = trigger
    return trigger