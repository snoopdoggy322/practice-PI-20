 #include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct Decimal;
typedef struct Decimal
{
    int val;
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
        free(d->prev);
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
* Read decimal from console
*/
Decimal * enterDecimal(void)
{
    Decimal * d = NO_DECIMAL;
    Decimal * current = d;
    char c;
    scanf("%c", &c);
    do
    {
        current = newDecimal(c - '0', current);
        if(d == NO_DECIMAL)
            d = current;
        scanf("%c", &c);
    } while(c >= '0' && c <= '9');
    return d;
}

void printDecimal(Decimal * current)
{
    current = head(current);
    if(current->val < 0)
        printf("-");
    do
    {
        printf("%c", abs(current->val) + '0');
        current = current->next;
    } while(current != NO_DECIMAL);
    printf("\n");
}

Decimal * substract(Decimal * a, Decimal * b)
{
    Decimal * lastA = tail(a), * lastB = tail(b), * result = NO_DECIMAL;
    int8_t sign = 0;
    while(lastA != NO_DECIMAL && lastB != NO_DECIMAL)
    {
        result = revNewDecimal(lastA->val - lastB->val, result);
        lastA = lastA->prev;
        lastB = lastB->prev;
        if(result->val < 0)
            sign = -1;
        else if(result->val > 0)
            sign = 1;
    }

    if(lastA != NO_DECIMAL)
    {
        while(lastA != NO_DECIMAL)
        {
            result = revNewDecimal(lastA->val, result);
            lastA = lastA->prev;
        }
        sign = 1;
    }
    else if(lastB != NO_DECIMAL)
    {
        while(lastB != NO_DECIMAL)
        {
            result = revNewDecimal(-lastB->val, result);
            lastB = lastB->prev;
        }
        sign = -1;
    }

    // Fix result number
    result = tail(result);
    while(result->prev != NO_DECIMAL)
    {
        if(sign > 0 && result->val < 0)
        {
            result->prev->val--;
            result->val += 10;
        }
        else if(sign < 0 && result->val > 0)
        {
            result->prev->val++;
            result->val -= 10;
        }
        result = result->prev;
    }
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

/** TESTS **/
int sub(int a, int b)
{
    return a - b;
}
void visualSimpleTest(int aValid, int bValid, int (*op)(int, int), BinOperation operation)
{
    char val[32] = {[0 ... 31] = 0};
    Decimal * a, * b, * result;
    sprintf(val, "%d\0", aValid);
    a = fromStr(val);
    sprintf(val, "%d\0", bValid);
    b = fromStr(val);
    result = operation(a, b);
    printf("%d == ", op(aValid, bValid));
    printDecimal(result);
    eliminate(a);
    eliminate(b);
    eliminate(result);
}
/** END **/

int main()
{
    Decimal * a, * b, * result;
    BinOperation operation = &substract;
    printf("Enter first decimal: \n");
    a = enterDecimal();
    printf("Enter second decimal: \n");
    b = enterDecimal();
    result = operation(a, b);
    printDecimal(result);

    eliminate(a);
    eliminate(b);
    eliminate(result);

/*	visualSimpleTest(96699, 87655, &sub, &substract);
	visualSimpleTest(966999, 87655, &sub, &substract);
	visualSimpleTest(9669, 87655, &sub, &substract);
	visualSimpleTest(9669, 9765, &sub, &substract);
	visualSimpleTest(9669, 9565, &sub, &substract);*/

    return 0;
}
