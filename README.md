<h1>DXLib Invader Game</h1>
<hr>
<p>This is a prototype <em>Space Invaders</em>-style game developed using <strong>DXLib</strong> and <strong>DirectX</strong> in C++.</p>
<hr>
<h2>Requirements</h2>
<ul>
    <li>
        <p><strong>DXLib</strong> must be installed<br>
        ↳ Reference: <a class="cursor-pointer" rel="noopener" target="_new">https://dxlib.xsrv.jp/</a><br>
        ↳ Include and link DXLib properly in your Visual Studio project</p>
    </li>
    <li>
        <p><strong>Windows + DirectX</strong></p>
    </li>
    <li>
        <p><strong>Visual Studio</strong> recommended (tested with VS2022)</p>
    </li>
</ul>
<hr>
<h2>Controls</h2>
<h3>Menu Screen</h3>
<ul>
    <li>
        <p><strong>Up/Down Arrow Keys</strong>: Select option</p>
    </li>
    <li>
        <p><strong>Space Key</strong>: Confirm selection</p>
    </li>
</ul>
<h3>Gameplay</h3>
<ul>
    <li>
        <p><strong>Right/Left Arrow Keys</strong>: Move player left/right</p>
    </li>
    <li>
        <p><strong>Space Key</strong>: Fire a shot</p>
    </li>
</ul>
<hr>
<h2>How to Build</h2>
<ol>
    <li>
        <p>Set <strong>working directory</strong> to <code>$(ProjectDir)</code> in your Visual Studio project settings.</p>
    </li>
    <li>
        <p>Ensure that <code>dxlib.h</code> and header files are correctly referenced.</p>
    </li>
    <li>
        <p>Build and run (<code>Ctrl + F5</code>).</p>
    </li>
</ol>
<hr>
<h2>Description</h2>
<p>This project is a small-scale shooting game inspired by the classic <em>Space Invaders</em>, created as a prototype using <strong>DirectX via DXLib</strong>.<br>
It features:</p>
<ul>
    <li>
        <p>Simple menu navigation</p>
    </li>
    <li>
        <p>Shot-based collision detection</p>
    </li>
    <li>
        <p>Enemy behavior and explosion effect</p>
    </li>
    <li>
        <p>Scene transitions (Menu / Play / Clear / Game Over)</p>
    </li>
</ul>
<hr>
<h2>Notes</h2>
<ul>
    <li>
        <p>Enemy movement logic is randomized slightly for variation.</p>
    </li>
    <li>
        <p>All game logic is managed within <code>gamePlay()</code> in <code>main.cpp</code>.</p>
    </li>
</ul>
<hr>
