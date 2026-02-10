char** sortPeople(char** names,int namesSize,int* heights,int heightsSize,int* returnSize){
    for(int i=0;i<namesSize;i++){
        for(int j=i+1;j<namesSize;j++){
            if(heights[i]<heights[j]){
               int h=heights[i];
               heights[i]=heights[j];
               heights[j]=h;
               char* n=names[i];
               names[i]=names[j];
               names[j]=n;
            }
        }
    }
    *returnSize=namesSize;
    return names;
}
