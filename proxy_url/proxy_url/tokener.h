#ifndef URL_TOKENER_H_
#define URL_TOKENER_H_

#include <assert.h>
#include <string.h>
#include <string>

namespace qh
{
    typedef unsigned int u32;
    typedef int s32;

    /**
    * A Tokener takes a source string and extracts characters and tokens from
    * it. It is used help to parse strings.
    * @version 2009-11-11
    */
    class Tokener
    {

    public:
        /**
        *	Construct a Tokener from a string.
        * @note	if needcopy = false, you MUST make sure the parameter string
        *	is available before we delete this Tokener.
        * @param s     A source string.
        */
        Tokener()
        {
            reset("", 0);
        }

        Tokener( const std::string& s );

        Tokener( const char* ps, const s32 ps_len = -1);

        /**
        * Calling this method is similar to reconstruct a new Tokener
        */
        void reset(const char* ps, const s32 ps_len = -1);

        ~Tokener();

        /**
        * Back up one character. This provides a sort of lookahead capability,
        * so that you can test for a digit or letter before attempting to parse
        * the next number or identifier.
        */
        bool back();

        /**
        * Back up several characters.
        * @param backstep - The count of back up steps
        */
        bool back(int backstep);

        /**
        * Get the next character in the source string.
        * This function will make the current position flag move to next position
        * @return The next character, or 0 if past the end of the source string.
        */
        char next();

        /**
        * Get the current character in the source string.
        *
        * @return The current character, or 0 if past the end of the source string.
        */
        char current();

        /**
        * Get the next char in the string, skipping whitespace.
        * @return  A character, or 0 if there are no more characters.
        */
        char nextClean();


        /**
        * Get the characters up to the next character <code>quote</code>.
        * Backslash processing is done.
        * If <code>quote</code> is not found, we do nothing and just
        * return a string empty "".
        * @param quote The quoting character, either
        *      <code>"</code>(double quote) or
        *      <code>'</code>(single quote) or
        *      other character
        * @return the string
        */
        std::string nextString( char quote );

        /**
        * Get the characters up to the next white space( or tab, \n, \r, \0 ) character.
        *
        * @return the string
        */
        std::string nextString();

        /**
        * Skip characters until the next character is the requested character.
        * If the requested character is not found, no characters are skipped.
        * @param to A character to skip to.
        * @return The requested character, or zero if the requested character
        * is not found.
        */
        char skipTo( char to );


        /**
        * Skip characters until come to a new line.
        * @remark If there is no new line, this function will do nothing.
        * @return true if successfully or false when failed.
        */
        bool skipToNextLine();

        /**
        * Skip characters until the previous character is the requested character.
        * If the requested character is not found, no characters are skipped.
        * @param to A character to skip to.
        * @return The requested character, or zero if the requested character
        * is not found.
        */
        char skipBackTo( char to );

        /**
        * Skip all whitespace, tab, \n
        * @return false if arrived end of string.
        */
        bool skipSpaces();


        /**
        * Get the hex value of a character (base16).
        * @param c A character between '0' and '9' or between 'A' and 'F' or
        * between 'a' and 'f'.
        * @return  An int between 0 and 15, or -1 if c was not a hex digit.
        */
        static int dehexchar( char c );

        /** Gets current read position in the buffer. It also serve as length of buffer parsed. */
        u32 getCurPos() const
        {
            return m_pCurPos - m_pData;
        }

        /** Gets current read position in the buffer. */
        const char* getCurReadPos() const
        {
            return m_pCurPos;
        }

        /** Query whether it is the end of the string.*/
        bool isEnd() const
        {
            return ( m_pCurPos >= m_pDataEnd || *m_pCurPos == '\0' );
        }

        /** Gets size of data that can read from the current read position. */
        s32 getReadableSize() const
        {
            return (s32)(m_pDataEnd - m_pCurPos);
        }

        const char* data() const { return m_pData;}
        size_t size() const { return m_pDataEnd - m_pData;}

    protected:
        void setCurrentPos( u32 icurentpos )
        {
            m_pCurPos = icurentpos + m_pData;
        }

        void setCurrentPos( const char* pos )
        {
            m_pCurPos = pos;
        }

    private:
        const char* m_pData;	//! the source text string to be parsed
        const char* m_pCurPos;  //! At first, set it 0
        const char* m_pDataEnd; //!
    };

    inline Tokener::Tokener( const std::string& s )
    {
        reset(s.c_str(), s.length());
    }

    inline Tokener::Tokener( const char* ps, const s32 len )
    {
        reset(ps, len);
    }

    inline void Tokener::reset( const char* ps, const s32 len )
    {
        m_pDataEnd = len + ps; 
        if ( len < 0 && ps )
        {
            m_pDataEnd = ps + strlen( ps );
        }

        m_pData   = const_cast<const char*>( ps );
        m_pCurPos = m_pData;
    }
    //----------------------------------------------------------------------------
    inline Tokener::~Tokener()
    {
    }

    //----------------------------------------------------------------------------
    inline bool Tokener::back()
    {
        if ( m_pCurPos <= m_pData )
        {
            fprintf(stderr, "Stepping back two steps is not supported\n" );
            return false;
        }

        --m_pCurPos;
        return true;
    }

    inline bool Tokener::back(int backstep)
    {
        if ( m_pCurPos - backstep < m_pData)
        {
            fprintf(stderr, "Stepping back two steps is not supported\n" );
            return false;
        }

        m_pCurPos -= backstep;
        return true;
    }

    //----------------------------------------------------------------------------
    inline int Tokener::dehexchar( char c )
    {
        if ( c >= '0' && c <= '9' )
        {
            return c - '0';
        }

        if ( c >= 'A' && c <= 'F' )
        {
            return c - ( 'A' - 10 );
        }

        if ( c >= 'a' && c <= 'f' )
        {
            return c - ( 'a' - 10 );
        }

        return -1;
    }

    inline char Tokener::next()
    {
        if ( isEnd() )
        {
            //! End of string
            ++m_pCurPos;
            return 0;
        }

        return *m_pCurPos++;
    }

    //----------------------------------------------------------------------------
    inline char Tokener::current()
    {
        if ( isEnd() )
        {
            return 0;
        }

        return *m_pCurPos;
    }


    //--------------------------------------------------------------------------
    inline char Tokener::nextClean()
    {
        for ( char c = 0; m_pCurPos < m_pDataEnd; )
        {
            c = *m_pCurPos++;

            /** c < 0 means This is not an ASCII character, like GBK code */
            if ( c > ' ' || c == 0 || c < 0)
            {
                return c;
            }
        }

        return 0;
    }

    inline std::string Tokener::nextString()
    {
        if ( isEnd() )
        {
            return "";
        }

        const char* startpos = m_pCurPos;

        for ( unsigned char c = 0; m_pCurPos < m_pDataEnd; )
        {
            c = *m_pCurPos++;

            if (c <= ' ')
            {
                return std::string( startpos, m_pCurPos - startpos - 1);
            }

            if (isEnd())
            {
                return std::string( startpos, m_pDataEnd - startpos );
            }
        }

        assert(false && "Logic ERROR. The routine SHOULD NOT come there.");
        return std::string();
    }


    inline std::string Tokener::nextString( char quote )
    {
        const char* startpos = m_pCurPos;

        while ( *m_pCurPos++ != quote )
        {
            if ( isEnd() )
            {
                m_pCurPos = startpos;
                return std::string();
            }
        }

        assert( m_pCurPos > startpos );
        return std::string( startpos, m_pCurPos - startpos - 1 );
    }

    inline char Tokener::skipTo( char to )
    {
        register char c = 0;
        const char* startIndex = this->m_pCurPos;

        do
        {
            c = next();

            if ( c == 0 )
            {
                m_pCurPos = startIndex;
                return c;
            }
        }
        while ( c != to );

        back();
        return c;
    }

    inline char Tokener::skipBackTo( char to )
    {

        const char* startIndex = this->m_pCurPos;

        do
        {
            if ( !back() )
            {
                m_pCurPos = startIndex;
                return 0;
            }
        }
        while ( current() != to );
        char c = current();
        next();
        return c;
    }

    //--------------------------------------------------------------------------
    inline bool Tokener::skipSpaces()
    {
        for ( char c = 0; m_pCurPos < m_pDataEnd; )
        {
            c = *m_pCurPos++;

            if ( c > ' ' || c <= 0)
            {
                back();
                return true;
            }
            else
            {
                continue;
            }
        }

        return false;
    }


    inline bool Tokener::skipToNextLine()
    {
        /**
        *  Windows line ending char is 0x0D0A
        *  Linux/Unix line ending char is 0x0A
        *  So, we just skipTo( 0x)0A )
        */

        char c = skipTo( (char)0x0a ); 
        if ( c == 0 )
        {
            return false;
        }

        // skip the last char of this line, and then go to a new line
        next(); 
        return true;
    }


};//end of namespace qh

#endif // #ifdef _OSLIB_TOKENER_H_


