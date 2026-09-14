00000000004017a8 <getbuf>:
  4017a8:       48 83 ec 28             sub    $0x28,%rsp                 # allocate 40 bytes on stack for input buffer
  4017ac:       48 89 e7                mov    %rsp,%rdi                  # rdi = pointer to top of stack (passed to Gets)
  4017af:       e8 8c 02 00 00          call   401a40 <Gets>              # read line from stdin into stack buffer
  4017b4:       b8 01 00 00 00          mov    $0x1,%eax                  # normal execution return value = 1
  4017b9:       48 83 c4 28             add    $0x28,%rsp                 # free 40 bytes stack frame
  4017bd:       c3                      ret                               # pop return address and jump
  4017be:       90                      nop
  4017bf:       90                      nop

00000000004017c0 <touch1>:
  4017c0:       48 83 ec 08             sub    $0x8,%rsp                  # align stack frame
  4017c4:       c7 05 0e 2d 20 00 01    movl   $0x1,0x202d0e(%rip)        # set vlevel = 1 at 0x6044dc
  4017cb:       00 00 00
  4017ce:       bf c5 30 40 00          mov    $0x4030c5,%edi             # load string pointer ("Touch1!...")
  4017d3:       e8 e8 f4 ff ff          call   400cc0 <puts@plt>          # print success message
  4017d8:       bf 01 00 00 00          mov    $0x1,%edi                  # pass phase level 1 to validate
  4017dd:       e8 ab 04 00 00          call   401c8d <validate>          # execute validation protocol
  4017e2:       bf 00 00 00 00          mov    $0x0,%edi                  # exit status 0
  4017e7:       e8 54 f6 ff ff          call   400e40 <exit@plt>          # terminate program cleanly

00000000004017ec <touch2>:
  4017ec:       48 83 ec 08             sub    $0x8,%rsp                  # align stack frame
  4017f0:       89 fa                   mov    %edi,%edx                  # copy input argument val to edx
  4017f2:       c7 05 e0 2c 20 00 02    movl   $0x2,0x202ce0(%rip)        # set vlevel = 2 at 0x6044dc
  4017f9:       00 00 00
  4017fc:       3b 3d e2 2c 20 00       cmp    0x202ce2(%rip),%edi        # check if input val == cookie at 0x6044e4
  401802:       75 20                   jne    401824 <touch2+0x38>       # jump to misfire block if not equal
  401804:       be e8 30 40 00          mov    $0x4030e8,%esi             # load success message format string
  401809:       bf 01 00 00 00          mov    $0x1,%edi
  40180e:       b8 00 00 00 00          mov    $0x0,%eax
  401813:       e8 d8 f5 ff ff          call   400df0 <__printf_chk@plt>  # print success text with cookie values
  401818:       bf 02 00 00 00          mov    $0x2,%edi                  # pass phase level 2 to validate
  40181d:       e8 6b 04 00 00          call   401c8d <validate>          # execute validation protocol
  401822:       eb 1e                   jmp    401842 <touch2+0x56>       # skip fail block
  401824:       be 10 31 40 00          mov    $0x403110,%esi             # load misfire format string
  401829:       bf 01 00 00 00          mov    $0x1,%edi
  40182e:       b8 00 00 00 00          mov    $0x0,%eax
  401833:       e8 b8 f5 ff ff          call   400df0 <__printf_chk@plt>  # print failure text with bad value
  401838:       bf 02 00 00 00          mov    $0x2,%edi                  # pass phase level 2 to fail
  40183d:       e8 0d 05 00 00          call   401d4f <fail>              # signal validation failure
  401842:       bf 00 00 00 00          mov    $0x0,%edi                  # exit status 0
  401847:       e8 f4 f5 ff ff          call   400e40 <exit@plt>          # terminate program

000000000040184c <hexmatch>:
  40184c:       41 54                   push   %r12                       # preserve callee-saved registers
  40184e:       55                      push   %rbp
  40184f:       53                      push   %rbx
  401850:       48 83 c4 80             add    $0xffffffffffffff80,%rsp   # allocate stack buffer space
  401854:       41 89 fc                mov    %edi,%r12d                 # r12d = cookie value
  401857:       48 89 f5                mov    %rsi,%rbp                  # rbp = pointer to input string
  40185a:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax              # get stack canary value
  401861:       00 00
  401863:       48 89 44 24 78          mov    %rax,0x78(%rsp)            # store canary on stack
  401868:       31 c0                   xor    %eax,%eax
  40186a:       e8 41 f5 ff ff          call   400db0 <random@plt>        # get random factor to shuffle stack layout
  40186f:       48 89 c1                mov    %rax,%rcx
  401872:       48 ba 0b d7 a3 70 3d    movabs $0xa3d70a3d70a3d70b,%rdx
  401879:       0a d7 a3
  40187c:       48 f7 ea                imul   %rdx                       # compute randomized buffer offset via modulo
  40187f:       48 01 ca                add    %rcx,%rdx
  401882:       48 c1 fa 06             sar    $0x6,%rdx
  401886:       48 89 c8                mov    %rcx,%rax
  401889:       48 c1 f8 3f             sar    $0x3f,%rax
  40188d:       48 29 c2                sub    %rax,%rdx
  401890:       48 8d 04 92             lea    (%rdx,%rdx,4),%rax
  401894:       48 8d 04 80             lea    (%rax,%rax,4),%rax
  401898:       48 c1 e0 02             shl    $0x2,%rax
  40189c:       48 29 c1                sub    %rax,%rcx
  40189f:       48 8d 1c 0c             lea    (%rsp,%rcx,1),%rbx         # rbx = randomized stack buffer destination address
  4018a3:       45 89 e0                mov    %r12d,%r8d                 # r8d = cookie value parameter
  4018a6:       b9 e2 30 40 00          mov    $0x4030e2,%ecx             # format string "%.8x"
  4018ab:       48 c7 c2 ff ff ff ff    mov    $0xffffffffffffffff,%rdx
  4018b2:       be 01 00 00 00          mov    $0x1,%esi
  4018b7:       48 89 df                mov    %rbx,%rdi                  # target randomized memory location
  4018ba:       b8 00 00 00 00          mov    $0x0,%eax
  4018bf:       e8 ac f5 ff ff          call   400e70 <__sprintf_chk@plt> # write hex string format of cookie into stack memory
  4018c4:       ba 09 00 00 00          mov    $0x9,%edx                  # compare exactly 9 bytes (8 hex digits + null terminator)
  4018c9:       48 89 de                mov    %rbx,%rsi                  # string reference on stack
  4018cc:       48 89 ef                mov    %rbp,%rdi                  # user input string address
  4018cf:       e8 cc f3 ff ff          call   400ca0 <strncmp@plt>       # match user string vs true cookie string
  4018d4:       85 c0                   test   %eax,%eax
  4018d6:       0f 94 c0                sete   %al                        # set return boolean flag (1 if match, 0 if not)
  4018d9:       0f b6 c0                movzbl %al,%eax
  4018dc:       48 8b 74 24 78          mov    0x78(%rsp),%rsi            # load canary reference
  4018e1:       64 48 33 34 25 28 00    xor    %fs:0x28,%rsi              # check for buffer overflow corruption
  4018e8:       00 00
  4018ea:       74 05                   je     4018f1 <hexmatch+0xa5>     # branch if frame is undamaged
  4018ec:       e8 ef f3 ff ff          call   400ce0 <__stack_chk_fail@plt> # abort execution if canary failed
  4018f1:       48 83 ec 80             sub    $0xffffffffffffff80,%rsp   # clean temporary stack footprint
  4018f5:       5b                      pop    %rbx                       # restore preserved registers
  4018f6:       5d                      pop    %rbp
  4018f7:       41 5c                   pop    %r12
  4018f9:       c3                      ret

00000000004018fa <touch3>:
  4018fa:       53                      push   %rbx                       # save registers
  4018fb:       48 89 fb                mov    %rdi,%rbx                  # rbx = pointer to user-supplied input string
  4018fe:       c7 05 d4 2b 20 00 03    movl   $0x3,0x202bd4(%rip)        # set vlevel = 3 at 0x6044dc
  401905:       00 00 00
  401908:       48 89 fe                mov    %rdi,%rsi                  # rsi = user input string reference address
  40190b:       8b 3d d3 2b 20 00       mov    0x202bd3(%rip),%edi        # edi = correct cookie value
  401911:       e8 36 ff ff ff          call   40184c <hexmatch>          # execute hex text evaluation string comparison
  401916:       85 c0                   test   %eax,%eax
  401918:       74 23                   je     40193d <touch3+0x43>       # fail if comparison return flag is 0
  40191a:       48 89 da                mov    %rbx,%rdx                  # load parameters for success message print
  40191d:       be 38 31 40 00          mov    $0x403138,%esi
  401922:       bf 01 00 00 00          mov    $0x1,%edi
  401927:       b8 00 00 00 00          mov    $0x0,%eax
  40192c:       e8 bf f4 ff ff          call   400df0 <__printf_chk@plt>  # print phase level 3 victory string
  401931:       bf 03 00 00 00          mov    $0x3,%edi                  # pass phase level 3 to validate
  401936:       e8 52 03 00 00          call   401c8d <validate>          # record success state
  40193b:       eb 21                   jmp    40195e <touch3+0x64>       # branch to clean shutdown exit
  40193d:       48 89 da                mov    %rbx,%rdx                  # load target parameters for failure notice
  401940:       be 60 31 40 00          mov    $0x403160,%esi
  401945:       bf 01 00 00 00          mov    $0x1,%edi
  40194a:       b8 00 00 00 00          mov    $0x0,%eax
  40194f:       e8 9c f4 ff ff          call   400df0 <__printf_chk@plt>  # print rejection data string
  401954:       bf 03 00 00 00          mov    $0x3,%edi                  # pass phase level 3 to fail
  401959:       e8 f1 03 00 00          call   401d4f <fail>              # reject run attempts
  40195e:       bf 00 00 00 00          mov    $0x0,%edi                  # exit status 0
  401963:       e8 d8 f4 ff ff          call   400e40 <exit@plt>          # exit execution

0000000000401968 <test>:
