import praw
import pandas as pd
import datetime as dt

def get_date(created):
    return dt.datetime.fromtimestamp(created)
class General:
    def __init__(self):
        self.CliedntId=
        self.ClientSecret=
        self.Username=
        self.Password=
        self.UserAgent=
        self.api =self.authenticate()
        
    def authenticate(self):
        auth = praw.Reddit(client_id=self.CliedntId,
                           client_secret=self.ClientSecret,
                           username=self.Username,
                           password=self.Password,
                           user_agent=self.UserAgent)
        api = auth.user
        try:
            api.me()
        except:
            print('FAILED to Connect! TRY AGAIN!!!')
        else:
            print("Connection Completed...")
            return auth
    
    def search_title(self,word,limit):
        multiplelist = {"title":[],
                        "score":[], 
                        "id":[], 
                        "url":[], 
                        "comms_num": [], 
                        "created": [], 
                        "body":[],
                        "up":[],
                        "down":[],
                        'subreddit' : word,
                        "author" :[],
                        "authoragain" :[]}
        count=0
        try:
            subreddit = self.api.subreddit(word)
            top_word = subreddit.top(limit=limit)
            cxz=0
            for submission in top_word:
                if not submission.stickied:
                        multiplelist["title"].append(submission.title)
                        multiplelist["score"].append(submission.score)
                        multiplelist["id"].append(submission.id)
                        multiplelist["url"].append(submission.url)
                        multiplelist["comms_num"].append(submission.num_comments)
                        multiplelist["created"].append(submission.created)
                        multiplelist["body"].append(submission.selftext)
                        multiplelist["up"].append(submission.ups)
                        multiplelist["down"].append(submission.downs) 
                        cxz+=1
                        if submission.author in multiplelist["author"] and submission.author:
                            a=0
                            multiplelist["authoragain"].append(a)
                        else:
                            a=1
                            count+=1
                            multiplelist["authoragain"].append(a)
                        multiplelist["author"].append(submission.author)
                        
        except praw.exceptions.PRAWException as f:
            print('ERROR',str(f))
            pass
            
        df =pd.DataFrame(multiplelist)
        timestamp = df["created"].apply(get_date)
        df = df.assign(timestamp = timestamp)
        df.to_csv('1_Reddit_data_{}_list.csv'.format(word), index=False)
        return count

baslat=General()
print(baslat.search_title('meToo',None),"  distinct users have been identified.")    
