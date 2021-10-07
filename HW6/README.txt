Part 1

Did the real and effective ID values change as you expected for user and group?

	Yes, they changed as expected.

Did the real and effective ID values change as expected for user and group?

	Yes, since mail isn't root the program didn't go past the first verification.

Part 2

Is the output the same as in Part 1 for both executions?

	For mail, yes, but, in order for the function to work properly you can never drop root privileges, otherwise you can't gain them back.
