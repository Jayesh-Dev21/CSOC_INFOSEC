# Task - forensics 13

part 13
	ubuntu@tryhackme:~cut -d ' ' -f2 access.log | sort |  uniq -c | nl
	     1	   5711 10.10.116.67
	     2	   4974 10.10.120.75
	     3	   5495 10.10.132.238
	     4	   5750 10.10.140.96
	     5	   5564 10.10.161.168
	     6	   4994 10.10.185.225
	     7	   5802 10.10.46.50
	     8	   5140 10.10.75.132
	     9	   5651 10.10.89.232


	ubuntu@tryhackme:~/Desktop/artefacts$ cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | nl
	     1	    423 account.activedirectory.windowsazure.com
	     2	    184 activity.windows.com
	     3	    680 admin.microsoft.com
	     4	    272 admin.onedrive.com
	     5	    304 adminwebservice.microsoftonline.com
	     6	    300 ajax.aspnetcdn.com
	     7	    282 api.passwordreset.microsoftonline.com
	     8	    316 appex.bing.com
	     9	    288 appsforoffice.microsoft.com
	    10	    272 autologon.microsoftazuread-sso.com
	    11	    274 becws.microsoftonline.com
	    12	    850 c.bing.com
	    13	    327 c.live.com
	    14	    456 c1.microsoft.com
	    15	    278 cacerts.digicert.com
	    16	    258 ccs.login.microsoftonline.com
	    17	    292 cdn.odc.officeapps.live.com
	    18	    240 cdn.uci.officeapps.live.com
	    19	    266 companymanager.microsoftonline.com
	    20	    306 compass-ssl.microsoft.com
	    21	    256 compliance.microsoft.com
	    22	    304 crl.globalsign.com
	    23	    308 dc.services.visualstudio.com
	    24	    300 defender.microsoft.com
	    25	    390 developer.microsoft.com
	    26	    232 device.login.microsoftonline.com
	    27	    274 dgps.support.microsoft.com
	    28	    606 docs.microsoft.com
	    29	    260 eus-www.sway-cdn.com
	    30	    306 eus-www.sway-extensions.com
	    31	    572 flow.microsoft.com
	    32	   1581 frostlings.bigbadstash.thm
	    33	    268 g.live.com
	    34	    265 geotrust.com
	    35	    462 github.com
	    36	    131 google.com
	    37	    260 graph.microsoft.com
	    38	   1554 learn.microsoft.com
	    39	    286 login-us.microsoftonline.com
	    40	    484 login.live.com
	    41	    300 login.microsoft.com
	    42	    278 login.microsoftonline-p.com
	    43	   4695 login.microsoftonline.com
	    44	    262 logincert.microsoftonline.com
	    45	    250 loginex.microsoftonline.com
	    46	    572 make.powerautomate.com
	    47	    113 mcgreedysecretc2.thm
	    48	    244 mscrl.microsoft.com
	    49	    310 msdn.microsoft.com
	    50	    238 nexus.microsoftonline-p.com
	    51	    278 o15.officeredir.microsoft.com
	    52	    118 ocsp.digicert.com
	    53	    141 ocsp.globalsign.com
	    54	    147 ocsp.msocsp.com
	    55	    134 ocsp2.globalsign.com
	    56	    128 ocspx.digicert.com
	    57	    316 office.com
	    58	    381 office.live.com
	    59	    274 office15client.microsoft.com
	    60	    238 officeapps.live.com
	    61	    270 officecdn.microsoft.com
	    62	    123 officeclient.microsoft.com
	    63	    276 officepreviewredir.microsoft.com
	    64	    242 officeredir.microsoft.com
	    65	    228 officespeech.platform.bing.com
	    66	    262 onenote.com
	    67	    520 outlook.office.com
	    68	    878 outlook.office365.com
	    69	     78 partnerservices.getmicrosoftkey.com
	    70	    290 passwordreset.microsoftonline.com
	    71	    288 platform.linkedin.com
	    72	    278 portal.cloudappsecurity.com
	    73	    264 powerapps.com
	    74	    396 powerapps.microsoft.com
	    75	    292 powerautomate.com
	    76	    333 prod.msocdn.com
	    77	    286 protection.office.com
	    78	    290 provisioningapi.microsoftonline.com
	    79	    266 r.office.microsoft.com
	    80	    284 secure.globalsign.com
	    81	    576 security.microsoft.com
	    82	    148 shellprod.msocdn.com
	    83	    390 signup.live.com
	    84	    282 skype.com
	    85	    622 smtp.office365.com
	    86	    282 ssw.live.com
	    87	    402 stackoverflow.com
	    88	    318 storage.live.com
	    89	    492 support.microsoft.com
	    90	    580 sway.com
	    91	    580 sway.office.com
	    92	    300 teams.microsoft.com
	    93	    220 technet.microsoft.com
	    94	    290 verisign.com
	    95	    306 wus-www.sway-cdn.com
	    96	    260 wus-www.sway-extensions.com
	    97	    300 www.asp.net
	    98	    578 www.bing.com
	    99	    302 www.digicert.com
	   100	    264 www.geotrust.com
	   101	   1860 www.globalsign.com
	   102	    393 www.google.com
	   103	    284 www.microsoft365.com
	   104	    536 www.msn.com
	   105	   4992 www.office.com
	   106	    393 www.onenote.com
	   107	    423 www.skype.com
	   108	    322 www.sway.com
	   109	    290 www.verisign.com
	   110	    284 www.yammer.com
	   111	    284 yammer.com


   ubuntu@tryhackme:~/Desktop/artefacts$ grep "$(cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | sort -nr | nl | tail -n 1 | cut -d ' ' -f10)" access.log | cut -d ' ' -f6 | uniq -c
     	78 503


   ubuntu@tryhackme:~/Desktop/artefacts$ cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | sort -nr | nl
	     1	   4992 www.office.com
	     2	   4695 login.microsoftonline.com
	     3	   1860 www.globalsign.com

	     4	   1581 frostlings.bigbadstash.thm {matched the discription}
	     5	   1554 learn.microsoft.com
	     6	    878 outlook.office365.com
	     7	    850 c.bing.com
	     8	    680 admin.microsoft.com



   ubuntu@tryhackme:~grep -r "$(cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | sort -nr | nl | head -n 4 | tail -n 1 | cut -d '8' -f2 | cut -d ' ' -f2)" access.log |  cut -d ']' -f2 | cut -d ' ' -f2 | uniq -c| cut -d ' ' -f5
		10.10.185.225
 
   ubuntu@tryhackme:~/Desktop/artefacts$ grep -r "$(cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | sort -nr | nl | head -n 4 | tail -n 1 | cut -d '8' -f2 | cut -d ' ' -f2)" access.log |  cut -d ']' -f2 | cut -d ' ' -f2 | uniq -c| cut -d ' ' -f4
		1581

   ubuntu@tryhackme:~/Desktop/artefacts$ grep -r "$(cut -d ' ' -f3 access.log | cut -d ':' -f1 | sort | uniq -c | sort -nr | nl | head -n 4 | tail -n 1 | cut -d '8' -f2 | cut -d ' ' -f2)" access.log  | cut -d '=' -f2 | cut -d ' ' -f1 | base64 -d | grep { | cut -d ',' -f3
		THM{a_gift_for_you_awesome_analyst!}
