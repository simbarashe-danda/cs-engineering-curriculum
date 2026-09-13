0000000000400f43 <phase_3>:
  400f43:       48 83 ec 18             sub    $0x18,%rsp                 # allocate 24 bytes on stack
  400f47:       48 8d 4c 24 0c          lea    0xc(%rsp),%rcx             # rcx points to rsp+12 (val2)
  400f4c:       48 8d 54 24 08          lea    0x8(%rsp),%rdx             # rdx points to rsp+8 (val1)
  400f51:       be cf 25 40 00          mov    $0x4025cf,%esi             # format string pointer
  400f56:       b8 00 00 00 00          mov    $0x0,%eax
  400f5b:       e8 90 fc ff ff          call   400bf0 <__isoc99_sscanf@plt> # parse input to stack
                                                                  # Let the parsed ints be [val1, val2] stored on [rsp+8, rsp+12]
  400f60:       83 f8 01                cmp    $0x1,%eax                  # if items_parsed > 1
  400f63:       7f 05                   jg     400f6a <phase_3+0x27>      # go to bounds check
  400f65:       e8 d0 04 00 00          call   40143a <explode_bomb>
  400f6a:       83 7c 24 08 07          cmpl   $0x7,0x8(%rsp)             # if val1 <= 7
  400f6f:       77 3c                   ja     400fad <phase_3+0x6a>      # else explode bomb
  400f71:       8b 44 24 08             mov    0x8(%rsp),%eax             # eax = val1
  400f75:       ff 24 c5 70 24 40 00    jmp    *0x402470(,%rax,8)         # switch via indirect jump table
  400f7c:       b8 cf 00 00 00          mov    $0xcf,%eax                 # CASE 0: eax = 207
  400f81:       eb 3b                   jmp    400fbe <phase_3+0x7b>      # goto VERIFY
  400f83:       b8 c3 02 00 00          mov    $0x2c3,%eax                # CASE 1: eax = 707
  400f88:       eb 34                   jmp    400fbe <phase_3+0x7b>
  400f8a:       b8 00 01 00 00          mov    $0x100,%eax                # CASE 2: eax = 256
  400f8f:       eb 2d                   jmp    400fbe <phase_3+0x7b>
  400f91:       b8 85 01 00 00          mov    $0x185,%eax                # CASE 3: eax = 389
  400f96:       eb 26                   jmp    400fbe <phase_3+0x7b>
  400f98:       b8 ce 00 00 00          mov    $0xce,%eax                 # CASE 4: eax = 206
  400f9d:       eb 1f                   jmp    400fbe <phase_3+0x7b>
  400fa9:       b8 aa 02 00 00          mov    $0x2aa,%eax                # CASE 5: eax = 682
  400fa4:       eb 18                   jmp    400fbe <phase_3+0x7b>
  400fa6:       b8 47 01 00 00          mov    $0x147,%eax                # CASE 6: eax = 327
  400fab:       eb 11                   jmp    400fbe <phase_3+0x7b>
  400fad:       e8 88 04 00 00          call   40143a <explode_bomb>      # default case failure
  400fb2:       b8 00 00 00 00          mov    $0x0,%eax
  400fb7:       eb 05                   jmp    400fbe <phase_3+0x7b>
  400fb9:       b8 37 01 00 00          mov    $0x137,%eax                # CASE 7: eax = 311
  400fbe:       3b 44 24 0c             cmp    0xc(%rsp),%eax             # VERIFY: compare eax to val2
  400fc2:       74 05                   je     400fc9 <phase_3+0x86>      # if val2 == eax, success
  400fc4:       e8 71 04 00 00          call   40143a <explode_bomb>      # else explode bomb
  400fc9:       48 83 c4 18             add    $0x18,%rsp                 # free stack space
  400fcd:       c3                      ret
