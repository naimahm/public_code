# watching the voice and wondered how they figured out the twitter quick save
# python would be the most efficient way imo
import tweepy

consumer_key = ""
consumer_secret = ""

access_token = ""
access_token_secret = ""

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

voicesaves = api.search("#voicesaves")

caroline = 0
austin = 0

for i in range(0, voicesaves.__len__()):
    if 'caroline' in voicesaves[i].text:
        caroline += 1
    if 'austin' in voicessaves[i].text:
        austin += 1

if caroline > austin:
    print 'caroline'
else:
    print 'austin'