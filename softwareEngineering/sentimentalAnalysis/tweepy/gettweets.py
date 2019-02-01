#!/usr/bin/python3

# listen from the tweets
from tweepy.streaming import StreamListener
# auth the twitter account
from tweepy import OAuthHandler
from tweepy import Stream
import twitterCredentials


class TwitterStreamer():

    def steam_tweets(self, fetched_tweets_filename, hash tag list):
        # This handles Twitter authentication and the connection to the twitter streaming API.
        listener = StdOutListener()
    auth = OAuthHandler(twitterCredentials.CONSUMER_KEY,
                        twitterCredentials.CONSUMER_SECRET)
    auth.set_access_token(twitterCredentials.ACCESS_TOKEN,
                          twitterCredentials.ACCESS_TOKEN_SECRET)

    stream = Stream(auth, listener)

    stream.filter(track=['narendra modi', 'rahul gandhi', 'yogi adityanath'])


class StdOutListener(StreamListener):

    def on_data(self, data):
        print(data)
        return True

    def on_error(self, status):
        print(status)


if __name__ == "__main__":
    pass
    # listener = StdOutListener()
    # auth = OAuthHandler(twitterCredentials.CONSUMER_KEY,
    #                     twitterCredentials.CONSUMER_SECRET)
    # auth.set_access_token(twitterCredentials.ACCESS_TOKEN,
    #                       twitterCredentials.ACCESS_TOKEN_SECRET)

    # stream = Stream(auth, listener)

    # stream.filter(track=['narendra modi', 'rahul gandhi', 'yogi adityanath'])
