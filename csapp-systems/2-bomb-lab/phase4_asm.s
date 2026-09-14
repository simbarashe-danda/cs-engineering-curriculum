000000000040100c <phase_4>:
  40100c:       48 83 ec 18             sub    $0x18,%rsp                 # allocate 24 bytes on stack
  401010:       48 8d 4c 24 0c          lea    0xc(%rsp),%rcx             # rcx points to rsp+12 (val2)
  401015:       48 8d 54 24 08          lea    0x8(%rsp),%rdx             # rdx points to rsp+8 (val1)
  40101a:       be cf 25 40 00          mov    $0x4025cf,%esi             # format string pointer
  40101f:       b8 00 00 00 00          mov    $0x0,%eax
  401024:       e8 cc fc ff ff          call   400bf0 <__isoc99_sscanf@plt> # parse input to stack
                                                                  # Let the parsed ints be [val1, val2] stored on [rsp+8, rsp+12]
  401029:       83 f8 01                cmp    $0x1,%eax                  # if items_parsed > 1
  40102c:       7f 05                   jg     401035 <phase_4+0x29>      # go to bounds check
  40102e:       e8 07 04 00 00          call   40143a <explode_bomb>      # else explode bomb
  401033:       eb 18                   jmp    40104d <phase_4+0x41>
  401035:       83 7c 24 08 0e          cmpl   $0xe,0x8(%rsp)             # if val1 <= 14
  40103a:       76 05                   jbe    401041 <phase_4+0x35>      # proceed if valid boundary
  40103c:       e8 f9 03 00 00          call   40143a <explode_bomb>      # else explode bomb
  401041:       ba 0e 00 00 00          mov    $0xe,%edx                  # parameter 3: high bound = 14
  401046:       be 0x00 00 00 00        mov    $0x0,%esi                  # parameter 2: low bound = 0
  40104b:       8b 7c 24 08             mov    0x8(%rsp),%edi             # parameter 1: target = val1
  40104f:       e8 7a ff ff ff          call   400fce <func4>             # eax = func4(val1, 0, 14)
  401054:       83 f8 00                cmp    $0x0,%eax                  # if return value == 0
  401057:       74 05                   je     40105e <phase_4+0x52>      # proceed to check val2
  401059:       e8 dc 03 00 00          call   40143a <explode_bomb>      # else explode bomb
  40105e:       83 7c 24 0c 00          cmpl   $0x0,0xc(%rsp)             # if val2 == 0
  401063:       74 05                   je     40106a <phase_4+0x5e>      # success path
  401065:       e8 d0 03 00 00          call   40143a <explode_bomb>      # else explode bomb
  40106a:       48 83 c4 18             add    $0x18,%rsp                 # free stack space
  40106e:       c3                      ret
