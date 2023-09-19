int calPoints(char ** operations, int operationsSize){
   int* stack = (int*)malloc(operationsSize*sizeof(int));
   int top = -1;
   int sum = 0;
   for(int i=0;i<operationsSize;i++)
   {
    switch (*operations[i])
    {
        case '+':
            top++;
            stack[top]=stack[top-1]+stack[top-2];
            sum += stack[top];
            break;
        case 'D':
            top++;
            stack[top]=stack[top-1]*2;
            sum += stack[top];
            break;
        case 'C':
            sum -= stack[top];
            top--;
            break;  
        default:
            top++;
            stack[top]=atoi(operations[i]);  
            sum += stack[top];
    }
   }
    free(stack);
    return sum;
}
