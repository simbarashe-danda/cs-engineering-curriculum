0000000000400efc <phase_2>:
  400efc:       55                      push   %rbp
  400efd:       53                      push   %rbx
  400efe:       48 83 ec 28             sub    $0x28,%rsp                 # allocate 40 bytes on stack
  400f02:       48 89 e6                mov    %rsp,%rsi                  # rsi points to top of stack
  400f05:       e8 52 05 00 00          call   40145c <read_six_numbers>  # read six ints from user input and store on stack
                                                                  # Let the numbers be [v1,v2,..,v6] stored on [rsp, rsp+4 ,.., rsp+20]
                                                                  # Let the array of [v1,v2,..,v6] be intArr
  400f0a:       83 3c 24 01             cmpl   $0x1,(%rsp)                # if val1 == 1
  400f0e:       74 20                   je     400f30 <phase_2+0x34>      # go to LOOP_INIT
  400f10:       e8 25 05 00 00          call   40143a <explode_bomb>+
  400f15:       eb 19                   jmp    400f30 <phase_2+0x34>
                                                                # LOOP : (while rbx != intArr+24): intArr+24 is out of bound pointer
  400f17:       8b 43 fc                mov    -0x4(%rbx),%eax          # eax = *(intArr-4)
  400f1a:       01 c0                   add    %eax,%eax                # eax = 2*eax
  400f1c:       39 03                   cmp    %eax,(%rbx)
  400f1e:       74 05                   je     400f25 <phase_2+0x29>    # if new_eax == *(rbx)
  400f20:       e8 15 05 00 00          call   40143a <explode_bomb>    # explode
  400f25:       48 83 c3 04             add    $0x4,%rbx                # else increment rbx: ptr
  400f29:       48 39 eb                cmp    %rbp,%rbx                # Loop condition check
  400f2c:       75 e9                   jne    400f17 <phase_2+0x1b>
  400f2e:       eb 0c                   jmp    400f3c <phase_2+0x40>
  400f30:       48 8d 5c 24 04          lea    0x4(%rsp),%rbx         # LOOP_INIT: rbx points to rsp+4. (rbx is a pointer to intArr+4)
  400f35:       48 8d 6c 24 18          lea    0x18(%rsp),%rbp        # rbp points to rsp+24
  400f3a:       eb db                   jmp    400f17 <phase_2+0x1b>  # goto LOOP
  400f3c:       48 83 c4 28             add    $0x28,%rsp
  400f40:       5b                      pop    %rbx
  400f41:       5d                      pop    %rbp
  400f42:       c3                      ret