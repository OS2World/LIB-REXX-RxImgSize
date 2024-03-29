.* Generated by HTML2HLP on 18 May 2014.
:userdoc.
:docprof toc=123456.
.*
.* author: Jan-Erik L�rka
.* description: Support library for REXX
.* generator: VyperHelp 1.11
.* generator: Mozilla/4.61 [en] (OS/2; U) [Netscape]
.* generator: KompoZer version 0.8b4pre 20100331 (OS/2 and eComStation)
:title.Raster&rbl.Image&rbl.Support&rbl.for&rbl.REXX
:h1 id=34717.RxImgSze&colon.&rbl.Raster&rbl.Image&rbl.Support&rbl.for&rbl.REXX
:artwork name='D:\HOME\RxImgSze\doc\RxImgSze.bmp' align=center.
:lines align=center.RxImgSze&colon.&rbl.Raster&rbl.Image&rbl.Support&rbl.for&rbl.Rexx:elines.
:lines align=center.:link reftype=hd refid='11349'.Copyright&rbl.�&rbl.2013&dash.2014&comma.&rbl.Jan&dash.Erik&rbl.L&ae.rka:elink.
:elines.
:lines align=center.:link reftype=launch object='netscdde.exe' data='-Xn http://www.xn-lrka-loa.com/'.http&colon.&slash.&slash.www&per.xn&dash.lrka&dash.loa&per.com&slash.:elink.
:elines.
:lines align=center.Raster&rbl.image&rbl.libraries&comma.&rbl.code&rbl.and&rbl.routines&rbl.from

.br
Generalized&rbl.Bitmap&rbl.Module&rbl.&lpar.GBM&rpar.&comma.
.br
currently&rbl.maintained&rbl.by&rbl.Heiko&rbl.Nitzsche&comma.&rbl.Germany&per.:elines.
:lines align=center.:link reftype=launch object='netscdde.exe' data='-Xn http://heikon.home.tlink.de/'.http&colon.&slash.&slash.heikon&per.home&per.tlink&per.de&slash.:elink.
:elines.
:h1 id=11349.License&rbl.agreement
.br
 
:i1 id=11349.License_agreement:hp2.License&rbl.agreement:ehp2.
.br
:p.Copyright&rbl.�&rbl.2013&dash.2014&comma.&rbl.Jan&dash.Erik&rbl.L&ae.rka
.br
All&rbl.rights&rbl.reserved&per.
.br
.br
Redistribution&rbl.and&rbl.use&rbl.in&rbl.source&rbl.and&rbl.binary&rbl.forms&comma.&rbl.with&rbl.or&rbl.without
modification&comma.&rbl.are&rbl.permitted&rbl.provided&rbl.that&rbl.the&rbl.following&rbl.conditions&rbl.are
met&colon.
.br
.br
1&per.&rbl.Redistributions&rbl.of&rbl.source&rbl.code&rbl.must&rbl.retain&rbl.the&rbl.above&rbl.copyright
notice&comma.&rbl.this&rbl.list&rbl.of&rbl.conditions&rbl.and&rbl.the&rbl.following&rbl.disclaimer&per.
.br
.br
2&per.&rbl.Redistributions&rbl.in&rbl.binary&rbl.form&rbl.must&rbl.reproduce&rbl.the&rbl.above
copyright&rbl.notice&comma.&rbl.this&rbl.list&rbl.of&rbl.conditions&rbl.and&rbl.the&rbl.following&rbl.disclaimer
in&rbl.the&rbl.documentation&rbl.and&slash.or&rbl.other&rbl.materials&rbl.provided&rbl.with&rbl.the
distribution&per.
.br
.br
3&per.&rbl.Neither&rbl.the&rbl.name&rbl.of&rbl.&apos.Jan&dash.Erik&rbl.L&ae.rka&apos.&rbl.nor&rbl.the&rbl.names&rbl.of&rbl.its
contributors&rbl.may&rbl.be&rbl.used&rbl.to&rbl.endorse&rbl.or&rbl.promote&rbl.products&rbl.derived&rbl.from
this&rbl.software&rbl.without&rbl.specific&rbl.prior&rbl.written&rbl.permission&per.
.br
.br
THIS&rbl.SOFTWARE&rbl.IS&rbl.PROVIDED&rbl.BY&rbl.THE&rbl.COPYRIGHT&rbl.HOLDERS&rbl.AND&rbl.CONTRIBUTORS&rbl.&apos.AS
IS&apos.&rbl.AND&rbl.ANY&rbl.EXPRESS&rbl.OR&rbl.IMPLIED&rbl.WARRANTIES&comma.&rbl.INCLUDING&comma.&rbl.BUT&rbl.NOT&rbl.LIMITED
TO&comma.&rbl.THE&rbl.IMPLIED&rbl.WARRANTIES&rbl.OF&rbl.MERCHANTABILITY&rbl.AND&rbl.FITNESS&rbl.FOR&rbl.A
PARTICULAR&rbl.PURPOSE&rbl.ARE&rbl.DISCLAIMED&per.&rbl.IN&rbl.NO&rbl.EVENT&rbl.SHALL&rbl.THE&rbl.COPYRIGHT
HOLDER&rbl.OR&rbl.CONTRIBUTORS&rbl.BE&rbl.LIABLE&rbl.FOR&rbl.ANY&rbl.DIRECT&comma.&rbl.INDIRECT&comma.&rbl.INCIDENTAL&comma.
SPECIAL&comma.&rbl.EXEMPLARY&comma.&rbl.OR&rbl.CONSEQUENTIAL&rbl.DAMAGES&rbl.&lpar.INCLUDING&comma.&rbl.BUT&rbl.NOT
LIMITED&rbl.TO&comma.&rbl.PROCUREMENT&rbl.OF&rbl.SUBSTITUTE&rbl.GOODS&rbl.OR&rbl.SERVICES&semi.&rbl.LOSS&rbl.OF&rbl.USE&comma.
DATA&comma.&rbl.OR&rbl.PROFITS&semi.&rbl.OR&rbl.BUSINESS&rbl.INTERRUPTION&rpar.&rbl.HOWEVER&rbl.CAUSED&rbl.AND&rbl.ON&rbl.ANY
THEORY&rbl.OF&rbl.LIABILITY&comma.&rbl.WHETHER&rbl.IN&rbl.CONTRACT&comma.&rbl.STRICT&rbl.LIABILITY&comma.&rbl.OR&rbl.TORT
&lpar.INCLUDING&rbl.NEGLIGENCE&rbl.OR&rbl.OTHERWISE&rpar.&rbl.ARISING&rbl.IN&rbl.ANY&rbl.WAY&rbl.OUT&rbl.OF&rbl.THE&rbl.USE
OF&rbl.THIS&rbl.SOFTWARE&comma.&rbl.EVEN&rbl.IF&rbl.ADVISED&rbl.OF&rbl.THE&rbl.POSSIBILITY&rbl.OF&rbl.SUCH&rbl.DAMAGE&per.
:h1 id=28296.Installation
:i1 id=28296.Installation
:hp2.Installation
:ehp2.
:p.
.br
Unpack&rbl.files&rbl.and&rbl.place&rbl.the&rbl.&per.dll&rbl.file&rbl.in
:link reftype=launch object='cmd.exe' data='/c open c:\ecs\dll'.C&colon.&bsl.ecs&bsl.dll:elink.
&rbl.or&rbl.:link reftype=launch object='cmd.exe' data='/c open C:\OS2\DLL'.C&colon.&bsl.OS2&bsl.DLL:elink.
&rbl.and&rbl.this&rbl.help&rbl.file&rbl.in&rbl.:link reftype=launch object='cmd.exe' data='/c open C:\ecs\book'.C&colon.&bsl.ecs&bsl.book:elink.
&rbl.or&rbl.:link reftype=launch object='cmd.exe' data='/c open C:\ecs\book'.C&colon.&bsl.OS2&bsl.BOOK:elink.

:h1 id=42381.Introduction&rbl.to&rbl.REXX
:i1 id=42381.Introduction_to_REXX
:hp2.Introduction
to&rbl.REXX
:ehp2.
.br
:p.REXX&rbl.extend&rbl.what&rbl.you&rbl.can&rbl.do&rbl.with&rbl.your&rbl.computer&per.
:p.Classic&rbl.REXX&rbl.that&rbl.ship&rbl.with&rbl.eComStation&rbl.and&rbl.OS&slash.2&rbl.allow&rbl.you&rbl.to&rbl.write
straight&rbl.forward&rbl.code&rbl.in&rbl.english&rbl.with&rbl.few&rbl.obstacles&rbl.as&rbl.rules&rbl.formatting
requirements&rbl.that&rbl.may&rbl.exist&rbl.in&rbl.other&rbl.similar&rbl.languages&per.
:p.The&rbl.REXX&rbl.language&rbl.allow&rbl.for&rbl.various&rbl.programming&rbl.styles&rbl.depending&rbl.on
your&rbl.personal&rbl.preference&comma.&rbl.which&rbl.may&rbl.confuse&comma.&rbl.but&rbl.also&rbl.allow&rbl.you&rbl.to
explore
it&rbl.and&rbl.try&rbl.more&per.
:p.Absolute&rbl.beginners&rbl.to&rbl.REXX&rbl.programming&rbl.should&rbl.read&rbl.one&rbl.of&rbl.the&rbl.REXX
introduction
tutorials&rbl.available&per.
:p.You&rbl.can&rbl.with&rbl.relatively&rbl.little&rbl.knowledge&rbl.extend&rbl.REXX&rbl.if&rbl.it&rbl.doesn&csq.t
contain
all&rbl.the&rbl.components&rbl.you&rbl.need&per.&rbl.This&rbl.library&rbl.is&rbl.an&rbl.example&rbl.of&rbl.how&rbl.you&rbl.can
add&rbl.functionallity&rbl.to&rbl.extend&rbl.REXX&rbl.beyond&rbl.the&rbl.original&rbl.implementation&per.
:h2 id=57790.Help&rbl.to&rbl.write&rbl.REXX&rbl.code
:i1 id=57790.Help_to_write_REXX_code:hp2.Help&rbl.to&rbl.write&rbl.REXX&rbl.code:ehp2.
:p.
.br
You&rbl.can&rbl.write&rbl.REXX&rbl.code&rbl.with&rbl.a&rbl.plain
:link reftype=launch object='e.exe'.Text&rbl.Editor:elink.

:p.Editors&rbl.with&rbl.support&rbl.for&rbl.programming&rbl.lanuages&rbl.usually&rbl.contain
various
functions&rbl.to&rbl.highlight&rbl.different&rbl.parts&rbl.of&rbl.the&rbl.code&rbl.to&rbl.inform&rbl.you&rbl.about
various&rbl.aspects&rbl.of&rbl.the&rbl.code&rbl.and&rbl.help&rbl.you&rbl.understand&rbl.it&rbl.better&per.
:p.:hp2.Example&rbl.of&rbl.Syntax&rbl.Highlightning:ehp2.
.br
:hp2.
:color fc=brown.&slash.&asterisk.:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&rbl.Filename&colon.&rbl.Example&per.cmd:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&rbl.Author&colon.&rbl.JAN&dash.ERIK:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&rbl.Created&colon.&rbl.Sat&rbl.Mar&rbl.22&rbl.2014:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&rbl.Purpose&colon.&rbl.Introductional&rbl.example&rbl.script
to&rbl.REXX:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&rbl.Changes&colon.:ehp2.
.br
:hp2.
:color fc=brown.&rbl.&rbl.&asterisk.&slash.:ehp2.
:p.:hp2.
:color fc=darkblue.SAY
:color fc=darkgreen.&apos.Example
of&rbl.Syntax&rbl.highlightning&apos.:ehp2.&rbl.
:p.:hp2.Examples&rbl.of&rbl.Text&rbl.Editors&rbl.with&rbl.Syntax&rbl.Highlightning:ehp2.
:p.:link reftype=hd refid='29968'.EPM&rbl.&lpar.Enhanced&rbl.Editor&rpar.:elink.

:p.:link reftype=hd refid='47356'.FTE&rbl.&lpar.Folding&rbl.Text&rbl.Editor&rpar.:elink.

:h2 id=29968.EPM&rbl.&lpar.Enhanced&rbl.Editor&rpar.
:i1 id=29968.EPM_Enhanced_Editor:hp2.EPM&rbl.&lpar.Enhanced&rbl.Editor&rpar.:ehp2.
:p.:link reftype=launch object='epm.exe'.EPM&rbl.&lpar.Enhanced&rbl.Editor&rpar.:elink.
&rbl.that&rbl.ships&rbl.with&rbl.OS&slash.2&rbl.and
eComstation&rbl.is&rbl.very
powerful&rbl.and&rbl.support&rbl.various&rbl.progamming&rbl.languages&comma.&rbl.not&rbl.only&rbl.REXX&per.&rbl.EPM
may&rbl.not&rbl.look&rbl.that&rbl.powerful&rbl.at&rbl.a&rbl.first&rbl.glance&rbl.if&rbl.you&rbl.haven&csq.t&rbl.tried&rbl.it
out&rbl.before&per.&rbl.You&rbl.can&rbl.however&rbl.add&rbl.buttons&rbl.to&rbl.the&rbl.buttonbar&rbl.of&rbl.the&rbl.EPM
that&rbl.add&rbl.support&rbl.for&rbl.syntax&rbl.highlightning&rbl.with&rbl.little&rbl.effort&per.
.br
&rbl.

:table frame=none rules=none cols='15 30'.
:row.
:c.Buttonbar&colon.&rbl.
:c.Right&rbl.click&rbl.
:row.
:c.Select&colon.&rbl.
:c.Buffet&rbl.
:row.
:c.Window&colon.&rbl.
:c.Toolbar&rbl.customization&rbl.
:row.
:c.Area&colon.&rbl.
:c.Buffet&rbl.toolbar&colon.&rbl.
:row.
:c.Click&colon.&rbl.
:c.>&rbl.&lpar.Right&rbl.most&rbl.button&rpar.&rbl.
:row.
:c.Button&colon.&rbl.
:c.&lbracket.&rbl.&rbl.KwdHilit&rbl.&rbl.&rbracket.&rbl.
:row.
:c.Drag&rbl.&amp.&rbl.Drop�&colon.&rbl.
:c.KwdHilit&rbl.
:row.
:c.Target&colon.&rbl.
:c.Current&rbl.toolbar&colon.&rbl.
:row.
:c.Button&colon.&rbl.
:c.&lbracket.&rbl.OK&rbl.&rbracket.&rbl.
:row.
:c.Window&colon.&rbl.
:c.EPM&rbl.main&rbl.window&rbl.
:row.
:c.Buttonbar&colon.&rbl.
:c.Right&rbl.click&rbl.
:row.
:c.Menu&colon.&rbl.
:c.Save&rbl.as&per.&per.&per.&rbl.
:row.
:c.Window&colon.&rbl.
:c.Save&rbl.Toolbar&rbl.
:row.
:c.Field&colon.&rbl.
:c.Enter&rbl.a&rbl.name&rbl.for&rbl.the&rbl.toolbar&per.&rbl.
:row.
:c.Type&colon.&rbl.
:c.Highlight&rbl.
:row.
:c.Window&colon.&rbl.
:c.EPM&rbl.main&rbl.window&rbl.
:row.
:c.Menu&colon.&rbl.
:c.:hp5.O:ehp5.ptions&rbl.>&rbl.P
:hp5.r
:ehp5.eferences
>&rbl.:hp5.S:ehp5.ettings&per.&per.&per.&rbl.
:row.
:c.Window&colon.&rbl.
:c.Settings&rbl.
:row.
:c.Tab&colon.&rbl.
:c.Toolbars&rbl.
:row.
:c.Grouping&rbl.area&colon.&rbl.
:c.Toolbars&rbl.
:row.
:c.Dropdown&colon.&rbl.
:c.Highlight&rbl.
:row.
:c.Button&colon.&rbl.
:c.&lbracket.&rbl.Make&rbl.current&rbl.&rbracket.&rbl.
:row.
:c.Close&rbl.window&colon.&rbl.
:c.Settings&rbl.
:etable.
�&rpar.&rbl.Drag&rbl.&amp.&rbl.Drop&rbl.with&rbl.the&rbl.Right&rbl.Mouse&rbl.Button

:h2 id=47356.FTE&rbl.&lpar.Folding&rbl.Text&rbl.Editor&rpar.
:i1 id=47356.FTE_Folding_Text_Editor:hp2.FTE&rbl.&lpar.Folding&rbl.Text
Editor&rpar.:ehp2.
:p.Various&rbl.versions&rbl.of&rbl.FTE&rbl.&lpar.Folding&rbl.Text&rbl.Editor&rpar.&rbl.exist&rbl.on&rbl.the&rbl.internet
and&rbl.they&rbl.provide&rbl.good&rbl.support&rbl.for&rbl.REXX&per.
:p.Syntax&rbl.Highlightning&comma.&rbl.automatic&rbl.Indention&rbl.to&rbl.ease&rbl.reading&rbl.and
debuggning
of&rbl.code&comma.&rbl.menus&rbl.to&rbl.insert&rbl.comments&rbl.and&rbl.useful&rbl.commands&rbl.within&rbl.the
languages
make&rbl.FTE&rbl.very&rbl.useful&per.
:p.
:hp2.Note
:ehp2.
:p.A&rbl.drawback&rbl.with&rbl.some&rbl.versions&rbl.of&rbl.FTE&rbl.is&rbl.that&rbl.the&rbl.folding&rbl.of&rbl.END&rbl.in
DO&dash.END
pair&rbl.sections&rbl.loose&rbl.track&rbl.of&rbl.position&rbl.and&rbl.in&rbl.default&rbl.configuration&rbl.with
OS&slash.2&rbl.version&rbl.doesn&csq.t&rbl.line&rbl.up&rbl.right&rbl.below&rbl.DO&per.
:p.:hp2.
:color fc=darkblue.IF&rbl.ARG
:color fc=darkcyan.&lpar.
:color fc=darkred.1
:color fc=darkcyan.&rpar.
&eq.
:color fc=darkred.1
:color fc=darkcyan.THEN:ehp2.
.br
:hp2.
:color fc=darkblue.DO:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.:hp2.
:color fc=darkblue.SAY
:color fc=darkgreen.&csq.Please
wait&per.&per.&per.&csq.:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.:hp2.
:color fc=darkblue.CALL
:color fc=darkcyan.SysSleep
:color fc=darkred.10:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.:hp2.
:color fc=darkcyan.END:ehp2.
:p.instead&rbl.of
:p.:hp2.
:color fc=darkblue.IF&rbl.ARG
:color fc=darkcyan.&lpar.
:color fc=darkred.1
:color fc=darkcyan.&rpar.
&eq.
:color fc=darkred.1
:color fc=darkcyan.THEN:ehp2.
.br
:hp2.
:color fc=darkblue.DO:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.:hp2.
:color fc=darkblue.SAY
:color fc=darkgreen.&csq.Please
wait&per.&per.&per.&csq.:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.:hp2.
:color fc=darkblue.CALL
:color fc=darkcyan.SysSleep
:color fc=darkred.10:ehp2.
.br
:hp2.
:color fc=darkcyan.END:ehp2.
:p.Internet&rbl.resources&rbl.for&rbl.FTE&rbl.&lpar.Folding&rbl.Text&rbl.Editor&rpar.&colon.
:p.:link reftype=launch object='netscdde.exe' data='-Xn http://www.os2site.com/sw/apps/editors/fte/index.html'.http&colon.&slash.&slash.www&per.os2site&per.com&slash.sw&slash.apps&slash.editors&slash.fte&slash.index&per.html:elink.

.br
:link reftype=launch object='netscdde.exe' data='-Xn http://hobbes.nmsu.edu/h-search.php?key=FTE+Editor&amp;pushbutton=Search'.http&colon.&slash.&slash.hobbes&per.nmsu&per.edu&slash.h&dash.search&per.php?key&eq.FTE&plus.Editor&amp.pushbutton&eq.Search:elink.

:h1 id=30862.Introduction&rbl.to&rbl.RxImgSze
:i1 id=30862.Introduction_to_RxImgSze:hp2.Introduction&rbl.to&rbl.RxImgSze:ehp2.
:sl compact.
:li.Display&rbl.Info&rbl.about&rbl.Image&rbl.
:li.Increase&rbl.Colors&rbl.in&rbl.Image&rbl.
:li.Reduce&rbl.Colors&rbl.in&rbl.Image&rbl.
:li.Resize&rbl.Image&rbl.
:li.Capture&rbl.a&rbl.Window&rbl.
:li.Capture&rbl.the&rbl.Desktop&rbl.
:li.Capture&rbl.a&rbl.Window&rbl.interior&rbl.
:li.Capture&rbl.parts&rbl.of&rbl.the&rbl.Desktop&slash.Window&rbl.
:esl.
:p.
.br
The&rbl.design&rbl.of&rbl.external&rbl.function&rbl.packages&rbl.allow&rbl.the&rbl.programmer&rbl.to
add&rbl.code&rbl.to&rbl.dynamically&rbl.handle&rbl.various&rbl.needs&rbl.in&rbl.just&rbl.i&rbl.functions&per.&rbl.This
has&rbl.been&rbl.explored&rbl.as&rbl.much&rbl.as&rbl.possible&rbl.in&rbl.this&rbl.library&rbl.and&rbl.require&rbl.you
as
a&rbl.reader&rbl.to&rbl.pay&rbl.attention&rbl.to&rbl.the&rbl.subtle&rbl.differences&rbl.between&rbl.the
provided
examples&per.
&rbl.
:p.:hp2.Library&rbl.functions:ehp2.
:table frame=none rules=none cols='15 2 43'.
:row.
:c.:link reftype=hd refid='53179'.rxImgLoadFuncs&rbl.:elink.

:c.&dash.&rbl.
:c.Load&rbl.all&rbl.other&rbl.functions&rbl.in&rbl.the&rbl.library&rbl.
:row.
:c.:link reftype=hd refid='57025'.rxImgDropFuncs&rbl.:elink.

:c.&dash.&rbl.
:c.Unload&rbl.all&rbl.other&rbl.functions&rbl.in&rbl.the&rbl.library&rbl.
:row.
:c.:link reftype=hd refid='27526'.rxImgVersion&rbl.:elink.

:c.&dash.&rbl.
:c.Show&rbl.information&rbl.for&rbl.this&rbl.library&rbl.
:row.
:c.:link reftype=hd refid='22310'.rxImgReSize&rbl.:elink.

:c.&dash.&rbl.
:c.Resize&rbl.and&rbl.reduce&slash.increase&rbl.colors&rbl.in&rbl.image&rbl.
:row.
:c.:link reftype=hd refid='27508'.rxImgCapture&rbl.:elink.

:c.&dash.&rbl.
:c.Capture&rbl.image&rbl.
:etable.
:h2 id=53179.rxImgLoadFuncs
:i1 id=53179.rxImgLoadFuncs
:hp2.rxImgLoadFuncs
:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.
.br
Syntax&colon.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.CALL&rbl.rxImgLoadFuncs

:table frame=none rules=none cols='13 75'.
:row.
:c.:hp3.Parameter&lpar.s&rpar.&rbl.
:ehp3.
:c.:hp3.Returns&slash.Note&rbl.
:ehp3.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.none&rbl.
:c.empty&rbl.string&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.
:c.Load&rbl.all&rbl.functions&rbl.for&rbl.usage&rbl.so
that&rbl.they&rbl.are&rbl.available&rbl.in&rbl.the&rbl.REXX&rbl.script
:etable.
:hp1.
.br
Example&rbl.
:ehp1.
.br
:hp2.
:color fc=darkblue.CALL
:color fc=darkcyan.RxFuncAdd
:color fc=darkgreen.&csq.rxImgLoadFuncs&csq.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&csq.rxImgSze&csq.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&csq.rxImgLoadFuncs&csq.
:ehp2.
.br
:hp2.
:color fc=darkblue.CALL
:color fc=darkcyan.rxImgLoadFuncs
:ehp2.
.br
:h2 id=57025.rxImgDropFuncs
:i1 id=57025.rxImgDropFuncs
:hp2.rxImgDropFuncs
:ehp2.
.br
&rbl.&rbl.&rbl.&rbl.
.br
Syntax&colon.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.CALL&rbl.rxImgDropFuncs

:table frame=none rules=none cols='13 49'.
:row.
:c.:hp3.Parameter&lpar.s&rpar.&rbl.
:ehp3.
:c.:hp3.Returns&slash.Note&rbl.
:ehp3.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.none&rbl.
:c.empty&rbl.string&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.
:c.Unload&rbl.all&rbl.previously&rbl.loaded
functions&rbl.when&rbl.done
:etable.
:h2 id=27526.rxImgVersion
:i1 id=27526.rxImgVersion:hp2.
:ehp2.
:hp2.rxImgVersion
:ehp2.
.br
.br
Syntax&colon.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.result&rbl.&eq.&rbl.rxImgVersion&lpar.&rbl.&lbracket.information&rbracket.&rbl.&rpar.

:table frame=none rules=none cols='15 58'.
:row.
:c.:hp3.Parameter&lpar.s&rpar.&rbl.
:ehp3.
:c.:hp3.Returns&slash.Note&rbl.
:ehp3.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.information&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.&rbl.:ehp1.
:row.
:c.none&rbl.&rbl.
:c.&apos.rxImgSize&colon.&rbl.version&rbl.1&per.03&comma.&rbl.GBM&colon.
version
1&per.12&apos.&rbl.
:row.
:c.&apos.RxImageSize&apos.&rbl.&rbl.
:c.&apos.1&per.03&apos.&rbl.
:row.
:c.&apos.GBM&apos.&rbl.&rbl.
:c.&apos.1&per.12&apos.&rbl.
:row.
:c.&rbl.&apos.Filters&apos.&rbl.
:c.&apos.nearestneighbor&comma.&rbl.bilinear&comma.
bell&comma.&rbl.bspline&comma.
&per.&per.&per.&apos.&rbl.
:row.
:c.&rbl.&apos.Palettes&apos.&rbl.
:c.&apos.BW&comma.&rbl.VGA&comma.&rbl.8B&comma.&rbl.4G&comma.&rbl.7x8x4&comma.&rbl.6x6x6&comma.
4x4x4&comma.
&per.&per.&per.&apos.&rbl.
:row.
:c.&rbl.&apos.Extra&apos.&rbl.
:c.&apos.ASPECT&comma.&rbl.ERRDIFF&comma.&rbl.HALFTONE&apos.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.&rbl.
:c.Return&rbl.information&rbl.about&rbl.this
library
and&rbl.capabilities&per.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Note&colon.&rbl.
:c.Only&rbl.the&rbl.first&rbl.letter&rbl.&lpar.if&rbl.any&rpar.
has&rbl.to
be&rbl.specified&per.&rbl.
:etable.
:p.:hp1.Example&rbl.1:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgVersion&lpar.&rpar.:ehp2.
:table frame=none rules=none cols='9 45'.
:row.
:c.Purpose&colon.&rbl.
:c.Get&rbl.general&rbl.information&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.rxImgSize&colon.&rbl.version&rbl.1&per.03&comma.&rbl.GBM&colon.
version
1&per.12&rbl.
:etable.
:p.
:hp1.Example&rbl.2
:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgVersion&lpar.
:color fc=darkgreen.&csq.R&csq.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 39'.
:row.
:c.Purpose&colon.&rbl.
:c.Get&rbl.information&rbl.about&rbl.the&rbl.rexx&rbl.library&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.1&per.03&rbl.
:etable.
:h2 id=22310.rxImgReSize
:i1 id=22310.rxImgReSize
:hp2.rxImgReSize
:ehp2.
.br
.br
Syntax&colon.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.result&rbl.&eq.&rbl.rxImgReSize&lpar.&rbl.input&us.image&lbracket.&comma.&rbl.output&us.image&comma.
&lbracket.width&rbracket.&comma.&rbl.&lbracket.height&rbracket.&comma.&rbl.&lbracket.options&rbracket.&lbracket.&comma.&rbl.palette&us.file&rbracket.&rbl.&rbracket.&rbl.&rpar.

:table frame=none rules=none cols='21 65'.
:row.
:c.:hp3.Parameter&lpar.s&rpar.
:ehp3.
:c.:hp3.Return&slash.Note
:ehp3.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.input&us.image&rbl.:ehp2.
:c.:hp1.&lpar.Mandatory&rpar.&rbl.
:ehp1.
:row.
:c.none&rbl.
:c.&apos.Syntax&colon.&rbl.rc&rbl.&eq.&rbl.rxImgReSize&lpar.&rbl.Source&us.path&us.and&us.filename&per.&per.&per.&apos.&rbl.
:row.
:c.&apos.C&colon.&bsl.nofile&per.xyz&apos.&rbl.
:c.&apos.2&apos.&rbl.
:row.
:c.&apos.C&colon.&bsl.GMARBLE&per.BMP&apos.&rbl.
:c.&apos.179&rbl.179&rbl.8&apos.&rbl.A&rbl.valid&rbl.filename&rbl.and&rbl.no&rbl.other&rbl.parameters&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.output&us.image&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.Will&rbl.use&rbl.the&rbl.input&rbl.file&rbl.for&rbl.output&rbl.e&per.g&per.&rbl.overwrite&rbl.it&per.&rbl.
:row.
:c.&apos.C&colon.&bsl.nofile&per.xyz&apos.&rbl.
:c.&apos.11&apos.&rbl.for&rbl.unknown&rbl.filetype&rbl.etc&per.&rbl.
:row.
:c.&apos.C&colon.&bsl.OUT&per.BMP&apos.&rbl.
:c.Will&rbl.write&rbl.the&rbl.file&rbl.if&rbl.it&csq.s&rbl.a&rbl.valid&rbl.image&rbl.format&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.width&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.keep&rbl.width&rbl.&lpar.unless&rbl.ASPECT&rbl.in&rbl.parameter&rbl.options&rpar.&rbl.
:row.
:c.120&rbl.
:c.Resize&rbl.image&rbl.to&rbl.120&rbl.pixels&rbl.wide&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.height&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.:ehp1.
:row.
:c.none&rbl.
:c.keep&rbl.height&rbl.&lpar.unless&rbl.ASPECT&rbl.in&rbl.parameter&rbl.options&rpar.&rbl.
:row.
:c.120&rbl.
:c.Resize&rbl.image&rbl.to&rbl.120&rbl.pixels&rbl.high&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.options&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.&dash.&rbl.
:row.
:c.&apos.nearestneighbor&apos.&rbl.
:c.Use&rbl.the&rbl.filter&rbl.nearestneighbor&rbl.during&rbl.resize&rbl.
:row.
:c.&apos.7x8x4&apos.&rbl.
:c.See&rbl.:link reftype=hd refid='27526'.Palettes:elink.

:row.
:c.&apos.1bpp&apos.&rbl.
:c.See&rbl.also&rbl.the&rbl.parameter&rbl.palette&us.file&rbl.below:link reftype=hd refid='34094'. :elink.

:row.
:c.&apos.ASPECT&apos.&rbl.
:c.&rbl.See&rbl.:link reftype=hd refid='27526'.Aspect:elink.

:row.
:c.&apos.ERRDIFF&apos.&rbl.
:c.&rbl.See&rbl.:link reftype=hd refid='27526'.Extra:elink.

:row.
:c.&apos.HALFTONE&apos.&rbl.
:c.&rbl.See&rbl.:link reftype=hd refid='27526'.Extra:elink.
:link reftype=hd refid='27526'. :elink.

:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.palette&us.file&rbl.:ehp2.
:c.:hp1.&lpar.Required&rbl.only&rbl.with&rbl.option
1bpp&comma.&rbl.4bpp
&amp.&rbl.8bpp&rpar.:ehp1.
:row.
:c.&apos.C&colon.&bsl.PaletteFile&per.xyz&apos.&rbl.
:c.&dash.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.and&slash.or&rbl.resize&rbl.image&comma.&rbl.reduce&rbl.or&rbl.increase&rbl.colors&rbl.of&rbl.image&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Note&colon.&rbl.
:c.A&rbl.return&rbl.value&rbl.of&rbl.0&rbl.indicate&rbl.&apos.no&rbl.problem&apos.&rbl.while&rbl.other&rbl.integer
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.values&rbl.indicate&rbl.various&rbl.problems&rbl.depending&rbl.on&rbl.input
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Extra&rbl.note&colon.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Pay&rbl.attention&rbl.to&rbl.the&rbl.special
case&rbl.when&rbl.you&rbl.only&rbl.provide&rbl.the&rbl.path
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.and&rbl.file&rbl.name&rbl.to&rbl.a&rbl.valid&rbl.image&per.
The&rbl.return&rbl.value&rbl.is&rbl.then
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.width&rbl.height&rbl.color&us.depth
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:etable.
:p.:hp1.Example&rbl.1:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 61'.
:row.
:c.Purpose&colon.&rbl.
:c.Get&rbl.information&rbl.about&rbl.width&comma.&rbl.height&rbl.and&rbl.color&rbl.depth&rbl.of&rbl.image&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.179&rbl.179&rbl.8&rbl.
:etable.
:p.:hp1.Example&rbl.2:ehp1.
.br
:hp2.
:color fc=darkblue.SAY&rbl.
:color fc=darkcyan.RxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE&per.GIF&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 47'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&rbl.and&rbl.save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.GIF&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.3:ehp1.
.br
:hp2.
:color fc=darkblue.SAY&rbl.
:color fc=darkcyan.RxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE&per.GIF&apos.
:color fc=darkcyan.&comma.
:color fc=darkred.120
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 55'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.width&rbl.to&rbl.120&rbl.pixels&rbl.and&rbl.keep&rbl.height&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.GIF
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.4:ehp1.
.br
:hp2.
:color fc=darkblue.SAY&rbl.
:color fc=darkcyan.RxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE&per.JPG&apos.
:color fc=darkcyan.&comma.&comma.&rbl.:ehp2.:hp2.
:color fc=darkred.150:ehp2.:hp2.
:color fc=darkcyan.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 60'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.height&rbl.to&rbl.150&rbl.pixels&rbl.high&rbl.and&rbl.keep&rbl.width&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.JPG
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.5:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE&per.PNG&apos.
:color fc=darkcyan.&comma.&comma.
:color fc=darkred.200
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.ASPECT&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 86'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.to&rbl.200&rbl.pixels&rbl.high&rbl.but&rbl.keep&rbl.aspect&rbl.ratio
between&rbl.width&rbl.and&rbl.height&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.PNG
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.6:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE2&per.GIF&apos.
:color fc=darkcyan.&comma.
:color fc=darkred.80
:color fc=darkcyan.&comma.&comma.
:color fc=darkgreen.&apos.GAUSSIAN&rbl.6x6x6&rbl.ERRDIFF&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 71'.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.width&rbl.to&rbl.80&rbl.pixels&rbl.wide&rbl.but&rbl.keep&rbl.height&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Use&rbl.Gaussian&rbl.filter&rbl.during&rbl.quality&rbl.scale&comma.&rbl.reduce&rbl.the&rbl.colors
with
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.&rbl.palette&rbl.6x6x6&rbl.and&rbl.error&rbl.diffusion&rbl.and&rbl.save&rbl.the&rbl.converted
image&rbl.as&rbl.GIF
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.7:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE2&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkred.350
:color fc=darkcyan.&comma.&comma.
:color fc=darkgreen.&apos.ASPECT&rbl.256&apos.
:color fc=darkcyan.&rbl.&rpar.:ehp2.
:table frame=none rules=none cols='9 93'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.width&rbl.to&rbl.350
pixels
wide&rbl.and&rbl.keep&rbl.aspect&rbl.ratio&rbl.between&rbl.width&rbl.and&rbl.height&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Reduce&rbl.colors&rbl.to&rbl.maxium
of&rbl.256&rbl.colors&rbl.and&rbl.save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.BMP
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.8:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE2&per.PNG&apos.
:color fc=darkcyan.&comma.&comma.
:color fc=darkred.500:ehp2.:hp2.
:color fc=darkcyan.&comma.:ehp2.:hp2.
:color fc=darkred.
:color fc=darkgreen.&apos.HALFTONE&rbl.KAISER
RGB&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 84'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.width&rbl.to&rbl.500&rbl.pixels&rbl.and&rbl.keep&rbl.height&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Use&rbl.Kaiser&rbl.filter&rbl.during&rbl.halftone&rbl.quality&rbl.scale&rbl.and&rbl.save&rbl.the
converted&rbl.image&rbl.as&rbl.PNG
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.9:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgReSize&lpar.
:color fc=darkgreen.&apos.C&colon.&bsl.OS2&bsl.BITMAP&bsl.GMARBLE&per.BMP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.GMARBLE3&per.BMP&apos.
:color fc=darkcyan.&comma.&comma.
:color fc=darkred.250
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.4bpp&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.Palfile&per.xyz&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 102'.
:row.
:c.Purpose&colon.&rbl.
:c.Copy&rbl.image&comma.&rbl.resize&rbl.height&rbl.to&rbl.250&rbl.pixels&rbl.and&rbl.keep&rbl.width&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.Reduce&rbl.colors&rbl.to&rbl.4&rbl.bit&rbl.&lpar.16&rbl.colors&rpar.&rbl.with&rbl.the&rbl.use&rbl.of&rbl.a&rbl.palette
file&rbl.and&rbl.save&rbl.the&rbl.converted&rbl.image&rbl.as&rbl.BMP
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:h2 id=27508.rxImgCapture
:i1 id=27508.rxImgCapture
:hp2.rxImgCapture
:ehp2.
.br
.br
Syntax&colon.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.result&rbl.&eq.&rbl.rxImgCapture&lpar.
window&us.name&lbracket.&comma.&rbl.left&us.coordinate&lbracket.&comma.&rbl.bottom&us.coordinate&lbracket.&comma.&rbl.right&us.coordinate&lbracket.&comma.
top&us.coordinate&lbracket.&comma.&rbl.save&us.as&us.path&us.and&us.filename&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rpar.
&rbl.&rbl.&rbl.&rbl.
.br
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
result&rbl.&eq.&rbl.rxImgCapture&lpar.&rbl.window&us.name&lbracket.&comma.&rbl.&apos.INTERIOR&apos.&slash.&apos.WINDOW&apos.&rbracket.&lbracket.&comma.
left&us.coordinate&lbracket.&comma.&rbl.bottom&us.coordinate&lbracket.&comma.&rbl.right&us.coordinate&lbracket.&comma.
top&us.coordinate&lbracket.&comma.&rbl.save&us.as&us.path&us.and&us.filename&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rbracket.&rbl.&rpar.
&rbl.&rbl.&rbl.&rbl.
.br
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
result&rbl.&eq.&rbl.rxImgCapture&lpar.&rbl.window&us.name&lbracket.&comma.&rbl.&apos.INTERIOR&apos.&slash.&apos.WINDOW&apos.&rbracket.&lbracket.&comma.
save&us.as&us.path&us.and&us.filename&rbl.&rbracket.&rbl.&rpar.
.br
:table frame=none rules=none cols='22 92'.
:row.
:c.:hp3.Parameter&lpar.s&rpar.&rbl.
:ehp3.
:c.:hp3.Return&slash.Note&rbl.
:ehp3.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.window&us.name&rbl.:ehp2.
:c.:hp1.&lpar.Mandatory&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.&apos.22&apos.&rbl.
:row.
:c.&apos.DESKTOP&apos.&rbl.
:c.&apos.0&apos.&rbl.
:row.
:c.&apos.Editor&apos.&rbl.
:c.Will&rbl.capture&rbl.a&rbl.window&rbl.with&rbl.the&rbl.title&rbl.name&rbl.&apos.Editor&apos.&rbl.or&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.if&rbl.none&rbl.with&rbl.just&rbl.that&rbl.name&rbl.a&rbl.window&rbl.that&rbl.contain&rbl.the&rbl.text
&apos.Editor&apos.&rbl.in&rbl.the&rbl.title
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.&apos.INTERIOR&apos.&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.&apos.INTERIOR&apos.&rbl.
:c.Will&rbl.capture&rbl.the&rbl.interior&rbl.of&rbl.the&rbl.window&rbl.instead&rbl.of&rbl.the&rbl.full
frame&rbl.
:row.
:c.&apos.WINDOW&apos.&rbl.
:c.Will&rbl.capture&rbl.the&rbl.whole&rbl.size&rbl.of&rbl.the&rbl.window&rbl.&lpar.default&rpar.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.left&us.coordinate&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.start&rbl.0&rbl.pixels&rbl.in&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.10l&rbl.
:c.start&rbl.10&rbl.pixles&rbl.from&rbl.left&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.10x&rbl.
:c.start&rbl.10&rbl.pixels&rbl.from&rbl.left&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.10&percent.&rbl.
:c.start&rbl.10&percent.&rbl.in&rbl.from&rbl.the&rbl.left&rbl.of&rbl.specified&rbl.window&rbl.&lpar.parameter
position&rbl.is&rbl.important&rpar.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.bottom&us.coordinate&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.
:ehp1.
:row.
:c.none&rbl.
:c.start&rbl.0&rbl.pixels&rbl.in&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.12b&rbl.
:c.start&rbl.12&rbl.pixles&rbl.from&rbl.bottom&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.12x&rbl.
:c.start&rbl.12&rbl.pixels&rbl.from&rbl.bottom&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.12&percent.&rbl.
:c.start&rbl.12&percent.&rbl.in&rbl.from&rbl.the&rbl.bottom&rbl.of&rbl.specified&rbl.window&rbl.&lpar.parameter
position&rbl.is&rbl.important&rpar.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.right&us.coordinate&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.:ehp1.
:row.
:c.none&rbl.
:c.start&rbl.0&rbl.pixels&rbl.in&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.14r&rbl.
:c.start&rbl.14&rbl.pixles&rbl.from&rbl.right&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.14w&rbl.
:c.14&rbl.pixels&rbl.wide&rbl.image&rbl.
:row.
:c.14&percent.&rbl.
:c.14&percent.&rbl.wide&rbl.image&rbl.of&rbl.specified&rbl.window&rbl.&lpar.parameter&rbl.position&rbl.is
important&rpar.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.top&us.coordinate&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.:ehp1.
:row.
:c.none&rbl.
:c.start&rbl.0&rbl.pixels&rbl.in&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.16t&rbl.
:c.start&rbl.16&rbl.pixles&rbl.from&rbl.top&rbl.of&rbl.specified&rbl.window&rbl.
:row.
:c.16h&rbl.
:c.16&rbl.pixels&rbl.high&rbl.image&rbl.
:row.
:c.16&percent.&rbl.
:c.16&percent.&rbl.high&rbl.image&rbl.of&rbl.specified&rbl.window&rbl.&lpar.parameter&rbl.position&rbl.is
important&rpar.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.:hp2.save&us.as&us.path&us.filename&rbl.:ehp2.
:c.:hp1.&lpar.Optional&rpar.:ehp1.
:row.
:c.none&rbl.
:c.defaults&rbl.to&rbl.&apos.temporary&per.bmp&apos.&rbl.in&rbl.the&rbl.current&rbl.directory&rbl.
:row.
:c.&apos.C&colon.&bsl.Captured&per.PNG&apos.&rbl.
:c.Saves&rbl.the&rbl.captured&rbl.image&rbl.as&rbl.Captured&per.PNG&rbl.in&rbl.C&colon.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Purpose&colon.&rbl.
:c.Capture&rbl.whole&rbl.or&rbl.part&rbl.of&rbl.the&rbl.screen&rbl.and&rbl.save&rbl.as&rbl.image&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Note&colon.&rbl.
:c.This&rbl.function&rbl.is&rbl.very&rbl.&apos.dynamic&apos.&rbl.and&rbl.only&rbl.the&rbl.first&rbl.and&rbl.last
parameter&rbl.has&rbl.fixed&rbl.positions&per.&rbl.
:etable.
:p.:hp1.Example&rbl.1:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgCapture&lpar.
:color fc=darkgreen.&apos.DESKTOP&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 77'.
:row.
:c.Purpose&colon.&rbl.
:c.Capture&rbl.the&rbl.whole&rbl.desktop&rbl.and&rbl.save&rbl.as&rbl.&apos.temporary&per.bmp&apos.&rbl.in&rbl.the
current&rbl.folder&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.2:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgCapture&lpar.
:color fc=darkgreen.&apos.DESKTOP&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.100b&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.50x&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.50&percent.&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.Capture1&per.bmp&apos.
:color fc=darkcyan.&rpar.:ehp2.
:table frame=none rules=none cols='9 72'.
:row.
:c.Purpose&colon.&rbl.
:c.Capture&rbl.parts&rbl.of&rbl.the&rbl.desktop&rbl.and&rbl.mix&rbl.values&comma.&rbl.save&rbl.to
&apos.C&colon.&bsl.Capture1&per.bmp&apos.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:p.:hp1.Example&rbl.3:ehp1.
.br
:hp2.
:color fc=darkblue.SAY
:color fc=darkcyan.rxImgCapture&lpar.
:color fc=darkgreen.&apos.Firefox&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.interior&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.150t&apos.
:color fc=darkcyan.&comma.
:color fc=darkgreen.&apos.C&colon.&bsl.Firefox&per.png&apos.
:color fc=darkcyan.&rbl.&rpar.:ehp2.
:table frame=none rules=none cols='9 66'.
:row.
:c.Purpose&colon.&rbl.
:c.Capture&rbl.interior&rbl.of&rbl.window&rbl.that&rbl.contain&rbl.the&rbl.name&rbl.Firefox&comma.&rbl.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.avoid&rbl.the&rbl.toolbar&rbl.buttons&rbl.at&rbl.the&rbl.top&rbl.and&rbl.save&rbl.to
&apos.C&colon.&bsl.Firefox&per.png&apos.
:row.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:c.
&rbl.&rbl.&rbl.&rbl.&rbl.&rbl.
:row.
:c.Output&colon.&rbl.
:c.0&rbl.
:etable.
:euserdoc.