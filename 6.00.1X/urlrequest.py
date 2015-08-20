import urllib2
import urllib

def URLRequest(url, params, method="GET"):
    data = urllib.urlencode(params)
    if method == "POST":
        return urllib2.Request(url, data)
    else:
        return urllib2.Request(url + "?" + data)


paramstr = ''
f = open('file.name', 'r')
for line in f:
    paramstr += line
f.close()

urlopener = urllib2.build_opener(urllib2.HTTPHandler())
request = URLRequest("https://...", {'param':paramstr}, "POST")
urlopener.open(request)

