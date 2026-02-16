Example 1:
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

#include <stdlib.h>
#include <string.h>

#define MAX_USERS 501
#define MAX_FEED 10

typedef struct Tweet {
    int id;
    int time;
    struct Tweet* next;
} Tweet;

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Tweet* tweets[MAX_USERS];
    Node* follows[MAX_USERS];
    int timestamp;
} Twitter;

int isFollowing(Node* head, int followeeId){
    Node* curr=head;
    while(curr){
        if(curr->val==followeeId) return 1;
        curr=curr->next;
    }
    return 0;
}

Node* newFollowNode(int val){
    Node* node=(Node*)malloc(sizeof(Node));
    node->val=val;
    node->next=NULL;
    return node;
}

Tweet* newTweet(int tweetId,int time){
    Tweet* t=(Tweet*)malloc(sizeof(Tweet));
    t->id=tweetId;
    t->time=time;
    t->next=NULL;
    return t;
}

typedef struct {
    Tweet* t;
    int user;
} HeapNode;

HeapNode heap[MAX_USERS];
int heapSize;

void swap(int i,int j){ HeapNode tmp=heap[i]; heap[i]=heap[j]; heap[j]=tmp; }

void heapPush(Tweet* t,int user){
    heap[heapSize].t=t;
    heap[heapSize].user=user;
    int i=heapSize++;
    while(i>0){
        int p=(i-1)/2;
        if(heap[p].t->time>=heap[i].t->time) break;
        swap(i,p);
        i=p;
    }
}

HeapNode heapPop(){
    HeapNode res=heap[0];
    heap[0]=heap[--heapSize];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<heapSize && heap[l].t->time>heap[largest].t->time) largest=l;
        if(r<heapSize && heap[r].t->time>heap[largest].t->time) largest=r;
        if(largest==i) break;
        swap(i,largest);
        i=largest;
    }
    return res;
}

Twitter* twitterCreate() {
    Twitter* obj=(Twitter*)malloc(sizeof(Twitter));
    memset(obj->tweets,0,sizeof(obj->tweets));
    memset(obj->follows,0,sizeof(obj->follows));
    obj->timestamp=0;
    return obj;
}

void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    Tweet* t=newTweet(tweetId,obj->timestamp++);
    t->next=obj->tweets[userId];
    obj->tweets[userId]=t;
}

int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    *retSize=0;
    heapSize=0;
    int* res=(int*)malloc(MAX_FEED*sizeof(int));
    if(obj->tweets[userId]) heapPush(obj->tweets[userId],userId);
    Node* f=obj->follows[userId];
    while(f){
        if(obj->tweets[f->val]) heapPush(obj->tweets[f->val],f->val);
        f=f->next;
    }
    while(heapSize>0 && *retSize<MAX_FEED){
        HeapNode top=heapPop();
        res[(*retSize)++]=top.t->id;
        if(top.t->next) heapPush(top.t->next,top.user);
    }
    return res;
}

void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    if(followerId==followeeId) return;
    if(isFollowing(obj->follows[followerId],followeeId)) return;
    Node* n=newFollowNode(followeeId);
    n->next=obj->follows[followerId];
    obj->follows[followerId]=n;
}

void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    Node* curr=obj->follows[followerId];
    Node* prev=NULL;
    while(curr){
        if(curr->val==followeeId){
            if(prev) prev->next=curr->next;
            else obj->follows[followerId]=curr->next;
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
}

void twitterFree(Twitter* obj) {
    for(int i=0;i<MAX_USERS;i++){
        Tweet* t=obj->tweets[i];
        while(t){
            Tweet* tmp=t;
            t=t->next;
            free(tmp);
        }
        Node* f=obj->follows[i];
        while(f){
            Node* tmp=f;
            f=f->next;
            free(tmp);
        }
    }
    free(obj);
}

