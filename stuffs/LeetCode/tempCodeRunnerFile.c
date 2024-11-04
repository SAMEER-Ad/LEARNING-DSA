    if (length < 1 || length > 500)
    {
        return false;
    }
    else
    {
        int count = 0;
        char first_letter = c[0];
        char last_letter = c[length - 1];
        printf("first letter is %c and lastone is %c\n", first_letter, last_letter);
        if (first_letter == last_letter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }