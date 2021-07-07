#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct Decimal;
typedef struct Decimal
{
    int8_t val;
    struct Decimal * next;
    struct Decimal * prev;
} Decimal;

#define NO_DECIMAL ((Decimal *)0)

typedef Decimal * (* BinOperation)(Decimal *, Decimal *);
typedef Decimal * (* MonoOperation)(Decimal *);

Decimal * newDecimal(int number, Decimal * parent)
{
    Decimal * d = malloc(sizeof(Decimal));
    d->val = number;
    d->prev = parent;
    if(parent != NO_DECIMAL)
        parent->next = d;
    return d;
}
Decimal * revNewDecimal(int number, Decimal * child)
{
    Decimal * d = malloc(sizeof(Decimal));
    d->val = number;
    d->next = child;
    d->prev = NO_DECIMAL;
    if(child != NO_DECIMAL)
        child->prev = d;
    return d;
}
Decimal * tail(Decimal * d)
{
    while(d->next != NO_DECIMAL)
        d = d->next;
    return d;
}
Decimal * head(Decimal * d)
{
    while(d->prev != NO_DECIMAL)
        d = d->prev;
    return d;
}
void eliminate(Decimal * d)
{
    d = head(d);
    do
    {
        d = d->next;
        d->prev->next = NO_DECIMAL;
        free(d->prev);
        d->prev = NO_DECIMAL;
    } while(d->next != NO_DECIMAL);
    free(d);
}
Decimal * trim(Decimal * d)
{
    d = head(d);
    while(d->next != NO_DECIMAL)
    {
        if(d->val != 0)
            break;
        d = d->next;
        free(d->prev);
        d->prev = NO_DECIMAL;
    }
    return d;
}
/**
* Read hexadecimal from console
*/
Decimal * enterHexadecimal(void)
{
    Decimal * d = NO_DECIMAL;
    Decimal * current = d;
    char c;
    scanf("%c", &c);
    do
    {
        if(c >= 'A' && c <= 'F')
            c = c - 'A' + 10;
        else if(c >= 'a' && c <= 'f')
            c = c - 'a' + 10;
        else if(c >= '0' && c <= '9')
            c -= '0';
        else
            break;
        current = newDecimal(c, current);
        if(d == NO_DECIMAL)
            d = current;
        scanf("%c", &c);
    } while(1);
    return d;
}

void printDecimal(Decimal * current)
{
    current = head(current);
    if(current->val < 0)
        printf("-");
    do
    {
        printf("%X", abs(current->val));
        current = current->next;
    } while(current != NO_DECIMAL);
    printf("\n");
}
Decimal * opOr(Decimal * a, Decimal * b)
{
    Decimal * lastA = tail(a), * lastB = tail(b), * result = NO_DECIMAL;
    while(lastA != NO_DECIMAL && lastB != NO_DECIMAL)
    {
        result = revNewDecimal(lastA->val | lastB->val, result);
        lastA = lastA->prev;
        lastB = lastB->prev;
    }

    if(lastA != NO_DECIMAL)
    {
        while(lastA != NO_DECIMAL)
        {
            result = revNewDecimal(lastA->val, result);
            lastA = lastA->prev;
        }
    }
    else if(lastB != NO_DECIMAL)
    {
        while(lastB != NO_DECIMAL)
        {
            result = revNewDecimal(lastB->val, result);
            lastB = lastB->prev;
        }
    }

    // Fix result number
    result = trim(result);

    return result;
}
Decimal * fromStr(char * str)
{
    Decimal * d = NO_DECIMAL;
    Decimal * current = d;
    do
    {
        current = newDecimal(*str - '0', current);
        if(d == NO_DECIMAL)
            d = current;
    } while(*++str != 0);
    return d;
}

int main()
{
    Decimal * a, * b, * result;
    BinOperation operation = &opOr;//&substract;
    printf("Enter first decimal: \n");
    a = enterHexadecimal();//enterDecimal();
    printf("Enter second decimal: \n");
    b = enterHexadecimal();//enterDecimal();
    result = operation(a, b);
    printDecimal(result);

    eliminate(a);
    eliminate(b);
    eliminate(result);


    return 0;
}
