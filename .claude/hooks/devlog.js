// Stop hook: a session that changed files must leave a dev-log entry for today before Claude stops.
// Exit 2 + stderr sends the reminder back to Claude once (stop_hook_active guards the second pass).
const fs = require("fs");
const { execSync } = require("child_process");
let input = "";
try { input = fs.readFileSync(0, "utf8"); } catch {}
if (/"stop_hook_active"\s*:\s*true/.test(input)) process.exit(0);
let dirty = "";
try { dirty = execSync("git status --porcelain", { stdio: ["ignore", "pipe", "ignore"] }).toString().trim(); } catch { process.exit(0); }
if (!dirty) process.exit(0);
const today = new Date().toISOString().slice(0, 10);
const log = `docs/dev-log/${today}.md`;
const changedToday = fs.existsSync(log) && Date.now() - fs.statSync(log).mtimeMs < 3 * 3600e3;
if (changedToday) process.exit(0);
process.stderr.write(`Files changed but ${log} was not updated. Append an entry (## what changed / decisions / next), move any durable decision into docs/decisions.md, then stop.\n`);
process.exit(2);
