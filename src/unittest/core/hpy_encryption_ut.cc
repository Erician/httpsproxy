#include <limits.h>
#include "gtest/gtest.h"
#include "core/hpy_encryption.h"
#include "core/hpy_decryption.h"

int string_cmp(unsigned char *str1, unsigned char *str2, int len)
{
    for(int i=0; i<len; i++)
    {
        if(str1[i] != str2[i])
            return -1;
    }
    return 0;
}

TEST(EncryptionTest, SimpleString_ShouldPass)
{
    unsigned char plain_text[8];
    unsigned char tmp_text[8];
    for(int i=0; i<7; i++)
    {
        plain_text[i] = 'a' + i;
        tmp_text[i] = 'a' + i;
    }
        
    plain_text[7] = '\0';
    tmp_text[7] = '\0';

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 1);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 1);
    //ASSERT_EQ("",tmp_text);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));
}


TEST(EncryptionTest, LittlehardString_ShouldPass)
{
    unsigned char plain_text[8];
    unsigned char tmp_text[8];
    for(int i=0; i<7; i++)
    {
        plain_text[i] = 250 + i;
        tmp_text[i] = 250 + i;
    }
        
    plain_text[7] = '\0';
    tmp_text[7] = '\0';

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 1);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 1);
    //ASSERT_EQ("",tmp_text);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));
}

TEST(EncryptionTest, DifferentKeys_ShouldPass)
{
    unsigned char plain_text[8];
    unsigned char tmp_text[8];
    for(int i=0; i<7; i++)
    {
        plain_text[i] = 250 + i;
        tmp_text[i] = 250 + i;
    }
        
    plain_text[7] = '\0';
    tmp_text[7] = '\0';

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 8);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 8);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 255);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 255);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 0);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 0);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));

    hpy::Tcp::Encryption::Encrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 0);
    hpy::Tcp::Decryption::Decrypt(hpy::Tcp::Encryption::kCaesarCipher, plain_text, 8, 0);
    ASSERT_EQ(0, string_cmp(plain_text, tmp_text, 8));

}