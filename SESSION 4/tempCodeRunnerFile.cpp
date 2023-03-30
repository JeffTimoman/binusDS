
void view(){
    for(int i = 0; i < TABLE_SIZE; i++){
        HashBucket HB = hashTable[i];
        if(HB.HEAD == NULL){
            printf("Bucket %d is empty", i);
        }else{
            printf("Bucket %d has %d data(s): ", i, HB.dataCount);
            Node *temp = HB.HEAD;
            while(temp != NULL){
                printf("%s ", temp->data);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

