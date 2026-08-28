#include <iostream>
#include <string>

//Utility for parsers 

// HTTP-message   = start-line CRLF
//                  *( field-line CRLF )
//                  CRLF
//                  [ message-body ]

//METHOD UTLITY

// 0 .. 9
bool is_digit(char input){
    return input >= '0' && input <= '9';
}

// a .. z && A .. Z
bool is_alpha(char input){
    return (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z');
}

// token  = 1*tchar
// tchar  = "!" / "#" / "$" / "%" / "&" / "'" / "*"
//           / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
//           / DIGIT / ALPHA
bool is_tchar(char input){
    return "!" || "#" || "$" || "%" || "&" || "'" || "*" || "+" || "-" || "." || "^" || "_"   || "`" || "|" || "~"|| is_digit(input) || is_alpha(input);
}

// REQUEST-TARGET UTILITY

// asterisk-form  = "*"
bool is_asterisk_form(std::string &input_string){
    return input_string == "*";
}

// origin-form = absolute-path [ "?" query ]
// absolute-path = 1*( "/" segment )
// query = *( pchar / "/" / "?" )
// segment = *pchar
// pchar = unreserved / pct-encoded / sub-delims / ":" / "@"
// unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"
// sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
//                / "*" / "+" / "," / ";" / "="
// pct-encoded = "%" HEXDIG HEXDIG
// query = *( pchar / "/" / "?" )
bool is_origin_form(){

}

// authority-form = uri-host ":" port
// host        = IP-literal / IPv4address / reg-name
// IP-literal = "[" ( IPv6address / IPvFuture  ) "]"
// IPvFuture  = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )
// IPv6address =                            6( h16 ":" ) ls32
//                   /                       "::" 5( h16 ":" ) ls32
//                   / [               h16 ] "::" 4( h16 ":" ) ls32
//                   / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
//                   / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
//                   / [ *3( h16 ":" ) h16 ] "::"    h16 ":"   ls32
//                   / [ *4( h16 ":" ) h16 ] "::"              ls32
//                   / [ *5( h16 ":" ) h16 ] "::"              h16
//                   / [ *6( h16 ":" ) h16 ] "::"
// IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet
// dec-octet   = DIGIT                 ; 0-9
                //   / %x31-39 DIGIT         ; 10-99
                //   / "1" 2DIGIT            ; 100-199
                //   / "2" %x30-34 DIGIT     ; 200-249
                //   / "25" %x30-35          ; 250-255
// reg-name    = *( unreserved / pct-encoded / sub-delims )
// unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"
// sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
//                / "*" / "+" / "," / ";" / "="
// pct-encoded = "%" HEXDIG HEXDIG
bool is_authority_form(){

}

// absolute-URI  = scheme ":" hier-part [ "?" query ]
// scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
// hier-part   = "//" authority path-abempty
//                   / path-absolute
//                   / path-rootless
//                   / path-empty
//  authority   = [ userinfo "@" ] host [ ":" port ]
//  userinfo    = *( unreserved / pct-encoded / sub-delims / ":" )
// unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"
// sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
//                / "*" / "+" / "," / ";" / "="
// pct-encoded = "%" HEXDIG HEXDIG
// host        = IP-literal / IPv4address / reg-name
// IP-literal = "[" ( IPv6address / IPvFuture  ) "]"
// IPvFuture  = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )
// IPv6address =                            6( h16 ":" ) ls32
//                   /                       "::" 5( h16 ":" ) ls32
//                   / [               h16 ] "::" 4( h16 ":" ) ls32
//                   / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
//                   / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
//                   / [ *3( h16 ":" ) h16 ] "::"    h16 ":"   ls32
//                   / [ *4( h16 ":" ) h16 ] "::"              ls32
//                   / [ *5( h16 ":" ) h16 ] "::"              h16
//                   / [ *6( h16 ":" ) h16 ] "::"
// IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet
// dec-octet   = DIGIT                 ; 0-9
                //   / %x31-39 DIGIT         ; 10-99
                //   / "1" 2DIGIT            ; 100-199
                //   / "2" %x30-34 DIGIT     ; 200-249
                //   / "25" %x30-35          ; 250-255
// reg-name    = *( unreserved / pct-encoded / sub-delims )
// port        = *DIGIT
//  path-abempty  = *( "/" segment )
//       path-absolute = "/" [ segment-nz *( "/" segment ) ]
//       path-noscheme = segment-nz-nc *( "/" segment )
//       path-rootless = segment-nz *( "/" segment )
//       path-empty    = 0<pchar>
// segment       = *pchar
// segment-nz    = 1*pchar
// segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" )
// pchar         = unreserved / pct-encoded / sub-delims / ":" / "@"

bool is_absolute_form(){

}

// HTTP-VERSION UTILITY

// HTTP-version  = HTTP-name "/" DIGIT "." DIGIT
// HTTP-name     = %s"HTTP"

bool is_http_version(){

}

// FIELD LINE UTILITY

// field-line   = field-name ":" OWS field-value OWS
// OWS  = *( SP / HTAB )
// field-name = token
// token  = 1*tchar
// tchar  = "!" / "#" / "$" / "%" / "&" / "'" / "*"
//           / "+" / "-" / "." / "^" / "_" / "`" / "|" / "~"
//           / DIGIT / ALPHA
// field-value    = *field-content
// field-content  = field-vchar
//                    [ 1*( SP / HTAB / field-vchar ) field-vchar ]
// field-vchar    = VCHAR / obs-text
// obs-text       = %x80-FF

bool is_field_line(){

}

// MESSAGE - BODY UTILITY

// message-body = *OCTET
// OCTET (any 8-bit sequence of data)

int parser_method(std::string &input_string , std::string &method){
    bool parse_succesful = true;
    for(int i = 0 ; i < int(input_string.size()) ; i++){
        if(!is_tchar(input_string[i])){
            parse_succesful = false;
            method.push_back(input_string[i]);
        }
    }
    if(parse_succesful) return 0;
    
    return -1;
}

