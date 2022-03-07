//
// Created by Zhong Bing on 8/9/20.
//
// Last year, I worked on the design for an interface box to a very large industrial power supply. This interface box had to accept commands and return parameter values over a RS-232 link. The communications used a set of simple ASCII mnemonics to specify the action to be taken. The mnemonics consisted of a channel number (0,1, or 2), followed by a two character parameter. The code to handle a read request coming in over the serial link is shown below. The function process_read() is called with a pointer to a string fragment that is expected to consist of the three characters (null terminated) containing the required command.

const CHAR *fna(void); // Example function prototype

static void process_read(const CHAR *buf)
{
    CHAR *cmdptr;
    UCHAR offset;
    const CHAR *replyptr;
    static const CHAR read_str[] =
    “0SV 0SN 0MO 0WF 0MT 0MP 0SW 1SP 1VO 1CC 1CA 1CB
    1ST 1MF 1CL 1SZ 1SS 1AZ 1AS 1BZ 1BS 1VZ 1VS 1MZ
    1MS 2SP 2VO 2CC 2CA 2CB 2ST 2MF 2CL 2SZ 2SS
    2AZ 2AS 2BZ 2BS 2VZ 2VS 2MZ 2MS “;
    static const CHAR *
    (* const readfns[sizeof(read_str)/4])(void) =
            {
                    fna,fnb,fnc, …
            };
    cmdptr = strstr(read_str, buf);
    if (cmdptr != NULL)
    {
/*
* cmdptr points to the valid command, so compute offset,
* in order to get entry into function jump table
*/
        offset = (cmdptr – read_str) / 4;/* Call function and get pointer to reply*/
        replyptr = (*readfns[offset])();
/* rest of the code goes here */
    }
}
