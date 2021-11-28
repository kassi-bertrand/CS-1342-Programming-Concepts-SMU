`Author(s)`: Billy Bertrand

`Project Description`:

A `C++` program that enables encryption and decryption of data using a variation of the *Caesar Cipher*.

Encryption of data using the Caesar Cipher is accomplished by taking the original message (plaintext) and
transforming each character using a key. The key is a number between `1 - 25` which indicates how many
letters to shift when encrypting the plain text. For instance lets say a user selects the key value 3 , the key
that Julius Caesar typically used with his cipher. We would then take the plaintext and shift each letter to
the left by `3` letters.

In this program, we are going to take that one step further, by using letters of a passcode to describe how
we rotate the characters (number of shifts to perform) in the plaintext message. For instance, providing
the passcode `ABC` and the plaintext message `ATTACK AT DAWN` would become the following

```
passcode: ABC
plaintext: ATTACK AT DAWN
ciphertext: AUVADM AU FAXP
```

where we start with the first letter of the message A and use the first letter of the passcode `A` to
indicate how we shift the alphabet to get the correct character. Since the passcodes first letter is A and
the first letter of the message is `A` , then the ciphertext character becomes `A` (shifting A by 0). The
second letter of the message `T` is paired with the second letter of the passcode `B` . So the character
becomes `T + 1` or `U` in the ciphertext. Then we move to the third letter of the message, using the third
letter of the passcode to get `V` (i.e. `T + 2` ). Then we repeat the process, starting over with the
beginning of the passcode after every `3` characters. So the fourth character we would use `A` as the
rotating key, and so on and so forth.

The more complex the passcode, the more secure your message will become!


`Why this project?`:

This was a programming project proposed in one of my programming class. I enjoyed working on it, so I thought it would be nice to archive it here.

`Program Specifications`:

You are to create a new project in CLion that allows a user to encrypt or decrypt messages using the
algorithm explained above. Your program will take commands from the user indicating the users intention.
The three commands are:

1. ENCRYPT
2. DECRYPT
3. QUIT

If a user enters ENCRYPT , your program should prompt the user to enter a passcode, then use that
passcode to encrypt a custom message entered via the keyboard.
If a user enters DECRYPT , you will first prompt the user to enter a passcode value, then prompt the user
to enter the ciphertext to decrypt.
Your program should display the passcode, the plaintext and cipher text as the output of each option.
And finally if a user enters EXIT you will exit the program.
NOTE: If a user does not enter a valid command, make sure to handle that error appropriately by re-prompting the user for a correct command.


`Result`:

```
Welcome to the SMU Encryption Engine!

Please Enter a command:
```
User enters `ENCRYPT`

```
Enter your passcode: SMU

Enter the message to be encrypted: Attack at dawn

Encrypting your message...

Passcode: SMU
Plaintext Message: ATTACK AT DAWN
Ciphertext Message: SFNSOE SF XSIH

Please Enter a command:
```
User enters `DECRYPT`

```
Enter your passcode: SMU
Enter the message to be decrypted: SFNSOE SF XSIH

Decrypting your message...

Passcode: SMU
Ciphertext Message: SFNSOE SF XSIH
Plaintext Message: ATTACK AT DAWN

Please Enter a command: 
```

User enters `BAD INPUT`

```
BAD INPUT is not a valid command. Please enter one of ENCRYPT/DECRYPT/QUIT

Please Enter a command:
```

User enters `QUIT`

```
Goodbye!
```

`Complications`:

- I was not aware of the behavior of the `modulo (%)` operator on negative numbers. As a result, I was getting corrupt results.

`Potential Improvements`:

- Further seperate functions into files

`Useful Resources`:

- https://torstencurdt.com/tech/posts/modulo-of-negative-numbers/

- https://qr.ae/pGSsjc